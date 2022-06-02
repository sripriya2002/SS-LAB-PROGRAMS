%{
	#include<stdio.h>
	int count=0;
%}
%%
(ab)* {count++;}{printf("entered pattern is %s",yytext);}
%%
void main()
{
printf("enter the pattern\n");
yylex();
printf("count is %d",count);
if(count>0)
	printf("pattern is matched\n");
else
	printf("pattern is not matched\n");
}
