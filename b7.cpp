#include<stdio.h>
#include<string.h>

int pos=-1;
int l,num;
char exp[100];
char id;

void E();
void T();
void Ed();
void Td();
void F();

void advance()
{
	pos++;
	if(pos<l)
	{
		if(exp[pos]>=0 && exp[pos]<=9)
		{
			num=exp[pos];
			id='\0';
		}
		if( (exp[pos]>='a' || exp[pos]>='A') && (exp[pos]<='z' || exp[pos]<='Z') )
		{
			id=exp[pos];
			num='\0';
		}
	}
}

void E()
{
	printf("E->TE'\n");
	T();
	Ed();
}
void T()
{
	printf("T->FT'\n");
	F();
	Td();
}

void Ed()
{
	int temp=1;
	if(exp[pos]=='+')
	{
		temp=0;
		advance();
		printf("E'->+TE'\n");
		T();
		Ed();
	}
	if(exp[pos]=='-')
	{
		temp=0;
		advance();
		printf("E'->-TE'\n");
		T();
		Ed();
	}
	if(temp==1)
	{
		printf("E'->null\n");
	}
}
void Td()
{
	int temp=1;
	if(exp[pos]=='*')
	{
		temp=0;
		advance();
		printf("T'->FT'\n");
		F();
		Td();
	}
	if(exp[pos]=='/')
	{
		temp=0;
		advance();
		printf("T'->/FT'\n");
		F();
		Td();
	}
	if(temp==1)
	{
		printf("T'->null\n");
	}
}
void F()
{
	if(exp[pos]==id)
	{
		advance();
		printf("F->id\n");
	}
	if(exp[pos]== '(' )
	{
		advance();
		E();
		if(exp[pos]== ')' )
		{
			advance();
		}
		printf("F->(E)\n");
	}
	if(exp[pos]==num)
	{
		advance();
		printf("F->num\n");
	}
}

int main()
{
	printf("Enter Expression:");
	scanf("%s",exp);
	l=strlen(exp);
	exp[l]='$';
	advance();
	E();
	if(pos==l)
	{
		printf("String Accepted!!");
	}
	else
	{
		printf("String NOT Accepted!!");
	}
}
