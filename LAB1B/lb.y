%{
#include<stdio.h>
#include<stdlib.h>
%}
%token Num ENTER
%left '+''-'
%left '*''/'
%%
input:exp ENTER {printf("Result is %d\n",$$);exit(0);}
exp: exp'+'exp{$$=$1+$3;}
|exp'-'exp{$$=$1-$3;}
|exp'*'exp{$$=$1*$3;}
|'('exp')'{$$=$2;}
|'-'exp{$$=-$2;}
|exp'/'exp{if($3==0){printf("divide by zero error");exit(0);}else $$=$1/$3;}
|Num{$$=$1;};			
%%
void main()
{
printf("enter the expression\n");
yyparse();
}
int yyerror()
{
printf("invalid expression\n");

}
