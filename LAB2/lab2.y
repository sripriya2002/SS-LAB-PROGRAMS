%{
#include<stdio.h>
#include<stdlib.h>
%}
%token ENTER A B
%%
stmt:s ENTER {printf("valid grammer");exit(0);}
s:A s1 B|B
s1:;|A s1
%%
void main()
{
printf("enter the string\n");
yyparse();
}
int yyerror()
{
printf("invalid expression\n");

}
