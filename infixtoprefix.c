/*authors: George Karagiannis and Aristidis Mouzakitis*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node
{
   char data;
   struct Node *next;
}*top = NULL;



void push(char);
void pop();
void converter();
int proteraiothta();
int proteraiothta2();

//global dhlwseis
char exprinf[50];        //arxikh ekfrash tou xrhsth
char reverse_exp[50];    //h ekfrash tou xrhsth reversed
char postfixd[50];       //meta8ematikh morfh ekfrashs
char prefixd[50];        //pro8ematikh morfh ekfrashs
int i=0,j=0,opval[2]={0,0};



//h main
int main(int argc, char *argv[])
{
	int choice,chk=0;



   printf("\n:: infix to prefix conversion ::\n");      //infix(en8ematikh) postfix(meta8ematikh) prefix(pro8ematikh)
   do{
      printf("\n****** MENU ******\n");
      printf("1. Input infix  expression\n2. Convert to prefix\n3. Exit\n");
      printf("Enter your Choice: ");
      scanf("%d",&choice);
      if(choice==1){
	  
	  	printf("Enter infix expression: ");
	  	while (getchar() != '\n');
	  	gets(exprinf);
	  	chk=1;
	  }
	  if(choice==2 && chk==1){
	  		int length=strlen(exprinf);
			for(i=length-1; i+1!=0; --i, ++j){        //bhma 1 ekfwnhshs,antistrofh
    			if (exprinf[i]==')')                //bhma 2 ekfwnhshs,antistrofh paren8esewn
					reverse_exp[j]='(';
			
				else if (exprinf[i]=='(')
					reverse_exp[j]=')';	
        		else
					reverse_exp[j]=exprinf[i];
       		
    		}
    		reverse_exp[j] ='\0'; 
			converter();                //bhma 3 ekfwnhshs,metatroph se prefix
			int length2=strlen(postfixd);
			j=0;
			for(i=length2-1; i+1!=0; --i, ++j){       
					prefixd[j]=postfixd[i];
       		
    		}
    		prefixd[j] ='\0'; 
			
	  }
    

 
  

	}while(choice!=3);



	printf("reverSED: ");
	puts(reverse_exp);
	printf("PostFIX: ");
  	puts(postfixd);
    printf("Prefix: ");
    puts(prefixd);
	return 0;  
}



//sunarthseis
int proteraiothta(){
	if(reverse_exp[i]=='^')
		return 3;
	if(reverse_exp[i]=='*'|| reverse_exp[i]=='/')	
		return 2;	
	if(reverse_exp[i]=='+'|| reverse_exp[i]=='-')
		return 1;	
}

int proteraiothta2(){
	if(top->data=='^')
		return 3;
	if(top->data=='*'|| top->data=='/')	
		return 2;	
	if(top->data=='+'|| top->data=='-')
		return 1;	
}

void converter(){
	i=0;
	j=0;
	do{
		if(isalpha(reverse_exp[i]) || isdigit(reverse_exp[i])){
			postfixd[j]=reverse_exp[i];
			j++;
		}
		else if(reverse_exp[i]=='('){
			push(reverse_exp[i]);	
		}

		else if(reverse_exp[i]=='+'){
			opval[0]=proteraiothta();
			
			while(opval[0]<=opval[1] && top!=NULL && top->data!='('){
				
				postfixd[j]=top->data;
				j++;
				pop();
			
			}
			push(reverse_exp[i]);
			
		}
		else if(reverse_exp[i]=='-'){
			opval[0]=proteraiothta();
			while(opval[0]<=opval[1]  && top!=NULL && top->data!='('){
				
		
				postfixd[j]=top->data;
				j++;
				pop();
			}
			push(reverse_exp[i]);
			
		}
		else if(reverse_exp[i]=='/'){
			opval[0]=proteraiothta();
			while(opval[0]<=opval[1]  && top!=NULL && top->data!='('){

				postfixd[j]=top->data;
				j++;
				pop();
			}
			push(reverse_exp[i]);
			
		}
		else if(reverse_exp[i]=='*'){
			opval[0]=proteraiothta();
			while(opval[0]<=opval[1]  && top!=NULL && top->data!='('){
				

				postfixd[j]=top->data;
				j++;
				pop();
			}

			push(reverse_exp[i]);
			
		}
		else if(reverse_exp[i]=='^'){
			opval[0]=proteraiothta();
			while(opval[0]<=opval[1]  && top!=NULL && top->data!='('){
				
				
	
				postfixd[j]=top->data;
				j++;
				pop();
			}
			push(reverse_exp[i]);
			
		}
		else if(reverse_exp[i]==')'){
			do{					      
				postfixd[j]=top->data;	
				j++;
				pop();	
			}while(top->data!='(');
			pop();
		}					
		i++;	
	}while(reverse_exp[i]!='\0');
	while(top!=NULL){                       //adeiasma stoivas,free mnhmhs
		postfixd[j]=top->data;
		j++;
		pop();
	}	
}

void push(char optmp)
{
   struct Node *newNode;
   newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = optmp;
   if(top == NULL)
      newNode->next = NULL;
   else
      newNode->next = top;
   top = newNode;
   if(top->data!='(')
   	  opval[1]=proteraiothta2();
   //printf("\nInsertion %c is Success, opval is %d!!!\n",top->data,opval[1]);
}
void pop()
{
   if(top->next == NULL)
      top=NULL;
   else{
      struct Node *temp = top;
      //printf("\nDeleted element: %c", temp->data);
      top = temp->next;
      free(temp);
      if(top->data!='(')
      	opval[1]=proteraiothta2();
   }
}

