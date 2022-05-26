%{
	#include<stdio.h>
	int count=0;
	
%}
%%
ab* {count++;} {printf("entered Pattern is %s",yytext);}

%%
int main()
{
printf("enter the sentence\n");
yylex();
if(count==1)
	printf("pattern is matched\n");
	else
	printf("pattern is not matched\n");
return 0;	
}
