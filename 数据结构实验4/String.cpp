/****************************************************

Name:              String.cpp
Auther:            Hawkeye
Date:            2018.10.24
Function:     test string.h

****************************************************/

#include<stdio.h>
#include<stdlib.h>
//#include<string.h>
#include"My_string.h"
//#include"kmp.h"

int main(){
	int i,judge,LS,LT,pos,l,next[20];
	char *c,mystr[20]={'\0'},a[20]={'\0'},b[20]={'\0'},g[20]={'\0'},h[20]={'\0'},e[20]={'\0'},d[20]={'\0'};
	//char wlm[100]="aaaab";
	c=mystr;
	String T,S,S1,S2,S3,S4;
	for(i=0;i<20;i++) next[i]=-5;

	//建立 
	printf("Please input a string\n\n");
	gets(mystr);
	puts(mystr);
	judge=StrAssign(S,mystr);
	if(judge)
		printf("\nCreate a string named 'S' successfully!\nS=");
	else
		printf("\nError!\n");
	for(i=0;*(S.ch+i)!='\0';i++){
		printf("%c",*(S.ch+i));
	}
	
	//复制 
	judge=StrCopy(T,S);
	if(judge)
		printf("\nCopy 'S' to 'T' successfully!\nT=");
	else
		printf("\nError!\n");
	for(i=0;*(T.ch+i)!='\0';i++){
		printf("%c",*(T.ch+i));
	}
	
	//求长度 
	LT=StrLength(T);
	LS=StrLength(S);
	printf("\nThe length of 'T' is %d.\nThe length of 'S' is %d.\n",LT,LS);
	
	//比较 
	judge=StrCompare(T,S);
	if(judge>0) printf("\nT>S\n");
	if(judge<0) printf("\nT<S\n");
	else printf("\nT=S\n");
	
	//连接 
	//a[20]={'\0'},b[20]={'\0'};
	printf("Please input the string you want connect1\n\n");
	gets(a);
	puts(a);
	judge=StrAssign(S1,a);
	if(judge)
		printf("\nCreate a string named 'S1' successfully!\nS1=");
	else
		printf("\nError!\n");
	for(i=0;*(S1.ch+i)!='\0';i++){
		printf("%c",*(S1.ch+i));
	}
	printf("\nPlease input the string you want connect2\n\n");
	gets(b);
	puts(b);
	judge=StrAssign(S2,b);
	if(judge)
		printf("\nCreate a string named 'S2' successfully!\nS2=");
	else
		printf("\nError!\n");
	for(i=0;*(S2.ch+i)!='\0';i++){
		printf("%c",*(S2.ch+i));
	}
	judge=StrConcat(T,S1,S2);
	if(judge)
	printf("\nLink 'T' and 'S' successfully!After link,'T' is\n");
	else printf("Error!");
	//if (!(T.ch=(char*)malloc((T.length+S.length)*sizeof(char)))) return OVERFLOW;
	for(i=0;*(T.ch+i)!='\0';i++){
		printf("%c",*(T.ch+i));
	}
	
	//截取 
	printf("\nPlease input string's position and length ---\n");
	scanf("%d%d",&pos,&l);
	judge=Substring(T,S,pos,l);
	if(judge)
		printf("\nCut 'S' to 'T' successfully!\nT=");
	else
		printf("\nError!\n");
	for(i=0;*(T.ch+i+1)!='\0';i++){
		printf("%c",*(T.ch+i));
	}
	//here!
	
	
	//free(S3.ch);
	//free(S4.ch);
	//替换
	//a[20]={'\0'},b[20]={'\0'};
	printf("\n\nPlease input the string you want to change\n\n");
	fflush(stdin);
	gets(d);
	//printf("Begin");
	puts(d);
	judge=StrAssign(S3,d);
	if(judge)
		printf("\nCreate a string named 'S1' successfully!\nS1=");
	else
		printf("\nError!\n");
	for(i=0;*(S3.ch+i)!='\0';i++){
		printf("%c",*(S3.ch+i));
	}
	printf("\nPlease input the string you want to change to\n\n");
	gets(e);
	puts(e);
	judge=StrAssign(S4,e);
	if(judge)
		printf("\nCreate a string named 'S2' successfully!\nS2=");
	else
		printf("\nError!\n");
	for(i=0;*(S4.ch+i)!='\0';i++){
		printf("%c",*(S4.ch+i));
	}
	printf("\nnext[] array is:\n");
	for(i=0;*(S3.ch+i)!='\0';i++){
		printf("%4c",*(S3.ch+i));
	}
	printf("\n"); 
	//S3.ch=wlm;
	get_next1(S3,next);
	i=0;
	while(next[i]!=0){
		printf("%4d",next[i]);
		i++;
	}
	//judge=StrReplace(T,S4,S3,next);
	if(judge)
		printf("\nReplace in 'T' successfully!\nT=");
	else
		printf("\nError!\n");
	for(i=0;*(T.ch+i)!='\0';i++){
		printf("%c",*(T.ch+i));
	}

	return 0; 
}
