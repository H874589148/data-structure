/****************************************************

Name:            CountTimess.c
Auther:            Hawkeye
Date:           2018.9.25
Function:    calculate a word appear how many times in a sentence

****************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void main(){
	char c[200]={"\0"},w[15]={"\0"};
	int i;
	printf("Please input a sentence---\n");              //读入句子 
	fflush(stdin);
	gets(c);
	printf("This is the sentence you typed---\n\n");     //输出刚才读入的句子 
	/*for(i=0;c[i]!=EOF;i++){
		printf("%c",c[i]);
	}*/
	puts(c);
	printf("\n\nPlease input the word you want to find---\n");     //读入想要查找的单词 
	gets(w);
	printf("You want to count the appearance times of --- ");      //输出想要查找的单词 
	/*for(i=0;c[i]!=EOF;i++){
		printf("%c",w[i]);
	}*/
	puts(w);
	int j=1,time=0;
	for(i=1;c[i]!=EOF&&w[j]!=EOF;i++){
		if(w[j]=c[i]){
			j++;
			if(w[j]==EOF){
				time++;
				j=0;
			}
		}
		else j=0;
	}
/*	s[0]=c[0];
	if(){
		s[i]=string\\\\\\\(￣▽￣)~*(￣▽￣)~*(￣▽￣)~*
	}*/
	printf("\n\nThis word's appearance times is %d.",time);
} 
