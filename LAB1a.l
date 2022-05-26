%{
#include<stdio.h>
int identifiers=0,operators=0,braces=0,alpha=0,spaces=0;
%}
%%
[a-zA-Z] {alpha++;printf("\nAlphabet:");ECHO;}
[0-9]* {identifiers++;printf("\nIdentifiers:");ECHO;}
[*|+] {operators++;printf("\nOperators:");ECHO;}
"(" {braces++;}
")" {braces--;}
[" "] {spaces++;}
.|\n {;}
%%
void main()
{
printf("enter the expression\n");
yylex();
if((braces==0) && (operators==identifiers-1) && alpha==0 && spaces==0)
{
	printf("\nValid Expression");
	printf("\nNumber of operators:%d",operators);
	printf("\nNumber of identifiers:%d",identifiers);
}
else
{
	printf("\nInValid Expression");
	printf("\n");
}
}
