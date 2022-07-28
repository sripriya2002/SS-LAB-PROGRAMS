%{
#include<stdio.h>
int id=0,op=0,digit=0,key=0;
extern FILE *yyin;
int yyerror();
int yylex();
%}
%token ID OP DIGIT KEYWORD
%%
input:ID input{id++;}
|ID {id++;}
|OP input{op++;}
|OP {op++;}
|DIGIT input{digit++;}
|DIGIT {digit++;}
|KEYWORD input{key++;}
|KEYWORD {key++;};
%%
void main()
{
yyin=fopen("sample.txt","r");
yyparse();
printf("ID count is %d\n",id);
printf("OP count is %d\n",op);
printf("DIGIT count is %d\n",digit);
printf("keywords count is %d\n",key);
}
int yyerror()
{
printf("invalid input\n");
return 0;
}
