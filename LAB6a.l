%{
#include<stdio.h>
int comment1=0,comment2=0,i=0;
%}
%%
[/][/].* {comment1++;}
[/][*].* {if(i==0) i++;}
[*][/] {if(i==1) i--;comment2++;}
. {if(i==0) ECHO;}
%%
void main()
{
yyin=fopen("program.c","r");
yyout=fopen("output.txt","w");
yylex();
printf("single line comments %d\n",comment1);
printf("multiline comments %d\n",comment2);
printf("total no of comments %d\n",comment1+comment2);
}
