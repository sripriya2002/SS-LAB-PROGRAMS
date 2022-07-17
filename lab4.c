#include<stdio.h>
#include<string.h>
char a[20],stk[20],ac[20],act[20];
int c=0,i=0,j=0,k=0,z=0;
void check();
void main(){
	puts("Grammer is :\n E->E+T|T \n T->T*F|F \n F->(E) \n F->id\n");
	puts("Enter the string\n");
	gets(a);
	c=strlen(a);
	strcpy(act,"SHIFT->");
	puts("stack\tinput\taction\n");
	puts("_________________________________________________\n");
	for(i=0,k=0;j<c;i++,j++,k++){
	if(a[j]=='i' && a[j+1]=='d'){
		stk[i]=a[j];
		stk[i+1]=a[j+1];
		stk[i+2]='\0';
		a[j]=' ';
		a[j+1]=' ';
		printf("$%s\t%s$\t%sid\n",stk,a,act);
		check();
	}
	else{
		stk[i]=a[j];
		stk[i+1]='\0';
		a[j]=' ';
		printf("$%s\t%s$\t%sSYMBOL\n",stk,a,act);
		check();
	}
	}
}
void check(){
	strcpy(ac,"REDUCE");
	
	for(z=0;z<c;z++){
		if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
			stk[z]='F';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
		}
	}
	for(z=0;z<c;z++){
		
		if(stk[z]=='i' && stk[z+1]=='d'){
			stk[z]='F';
			stk[z+1]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
			j++;
		}
	}
	for(z=0;z<c;z++){
		if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F'){
			stk[z]='T';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
		}
		else if(stk[z]=='F'){
			stk[z]='T';
			//stk[z+1]='\0';
			//stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
		}
	}
	for(z=0;z<c;z++){
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*')break;
		if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T'){
			if(a[j+1]=='*')break;
			else{
			stk[z]='E';
			stk[z+1]='\0';
			stk[z+2]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
			i=i-2;
			}
		}
		else if(stk[z]=='T'){
			stk[z]='E';
			//stk[z+1]='\0';
			printf("$%s\t%s$\t%s\n",stk,a,ac);
		}
	}
}
		
