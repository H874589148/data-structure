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
	int i=1;
	printf("Please input a sentence---\n");              //������� 
	c[0]=getchar();
	while(c[i-1]!=EOF){
		c[i]=getchar();
		i++;
	}
	//gets(c);
	printf("This is the sentence you typed---\n\n");     //����ղŶ���ľ��� 
	for(i=0;c[i]!=EOF;i++){
		printf("%c",c[i]);
	}
	printf("\n\nPlease input the word you want to find---\n");     //������Ҫ���ҵĵ��� 
	w[0]=getchar();
	i=1;
	while(w[i-1]!=EOF){
		w[i]=getchar();
		i++;
	}
	//gets(w);
	printf("You want to count the appearance times of --- ");      //�����Ҫ���ҵĵ��� 
	for(i=0;c[i]!=EOF;i++){
		printf("%c",w[i]);
	}
	int j=0,time=0;
	for(i=0;c[i]!=EOF&&w[j]!=EOF;i++){
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
		s[i]=string\\\\\\\(������)~*(������)~*(������)~*
	}*/
	printf("\n\nThis word's appearance times is %d.",time);
} 
