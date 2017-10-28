%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
extern FILE *yyin;
char addtotable(char,char,char);
struct expr{
	char operand1;
	char operand2;
	char operator;
	char result;
};


int index=0;
char temp='A'-1;
%}

%union{
	char symbol;
}
%token <symbol> LETTER NUMBER
%type <symbol> exp

%left '+' '-'
%left '/' '*'

%%
S: LETTER '='exp';' {addtotable((char)$1,(char)$3,'=');};
exp: exp '+' exp {$$=addtotable((char)$1,(char)$3,'+');}
	|exp '-' exp {$$=addtotable((char)$1,(char)$3,'-');}
	|exp '*' exp {$$=addtotable((char)$1,(char)$3,'*');}
	|exp '/' exp {$$=addtotable((char)$1,(char)$3,'/');}
	|'('exp')' {$$=(char)$2;}
	|NUMBER {$$=(char)$1;}
	|LETTER {(char)$1;};
%%

struct expr arr[20];

void yyerror(char *s)
{
	printf("Errror %s",s);
}

char addtotable(char o1,char o2,char op)
{
	temp++;
	arr[index].operand1=o1;
	arr[index].operand2=o2;
	arr[index].operator=op;
	arr[index].result=temp;
	index++;
	return temp;
}

void threeAdd()
{
	int i=0;
	while(i<index)
	{
		printf("%c :=\t%c\t%c\t%c\n",arr[i].result,arr[i].operand1,arr[i].operator,arr[i].operand2);
		i++;
	}
}

void quad()
{
	int i=0;
	while(i<index)
	{
		printf("%c\t%c\t%c\t%c\n",arr[i].operator,arr[i].operand1,arr[i].operand2,arr[i].result);
		i++;
	}	
}

int main()
{
	//printf("Enter the algebraic expression: ");
	yyin=fopen("sample","r");
	yyparse();
	printf("\nThree address code\n");
	threeAdd();
	printf("\n\nQuadraple\n");
	quad();
	return 0;
}

int yywrap()
{
	return 1;
}

//a=(5*b)/c+2;
//use sample file with algebraic expression
