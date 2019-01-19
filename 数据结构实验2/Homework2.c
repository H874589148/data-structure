/****************************************************

Name:            Homework2.c
Auther:            Hawkeye
Date:           2018.10.8
Function:    Data struct second computer homework

int idx[8] = {1,2,3,4,5,6,7,8};
int age[8] = {15,18,13,22,50,18,30,20};

****************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Hawkeye.h"

void MakeArray(int idx[],int age[],int len);

int main()
{
	int len,*idx,*age,delete_age;
	struct node*nd = NULL;
	nd = (struct node*)malloc(sizeof(struct node));
	//int idx[8] = {1,2,3,4,5,6,7,8};
	//int age[8] = {15,18,13,22,50,18,30,20};
	List L;
	printf("Please input the length of your List -----  ");                  //建立两个一维动态数组 idx[] age[]
	scanf("%d",&len);
	idx=(int *)malloc(len*sizeof(int));
	age=(int *)malloc(len*sizeof(int));
	if(idx==NULL || age==NULL){
		printf("Memory size not enough!\n");
		exit(1);
	}
	if(age==NULL){
		printf("Memory size not enough!\n");
		exit(1);
	}
	//printf("hu");
	MakeArray(idx,age,len);                                               //建立数组
	L = CreateList(idx,age,len);                                          //建立链表 
	PrintList(L);                                                         //打印链表 
	printf("Please input the age of person you want delete\ninput '0' end\n");
	scanf("%d",&delete_age);
	while(delete_age){
		//scanf("%d",&delete_age);
		L=DeleteNodeAge(L,delete_age);
		PrintList(L);
		printf("Please input the age of person you want delete\ninput '0' end\n");
		scanf("%d",&delete_age);
	}
	printf("Please input the message of the person you want insert\nage=0 end\n");
	scanf("%d%d",&(nd->idx),&(nd->age));
	while(nd->age){
		L = InsertNodeByIdx(L,nd);
		PrintList(L);
		printf("Please input the message of the person you want insert\nage=0 end\n");
		scanf("%d%d",&(nd->idx),&(nd->age));
	}
	printf("Please input the message of the person you want insert by age\n");
	scanf("%d%d",&(nd->idx),&(nd->age));
	L = InsertNodeByAge(L,nd);
	PrintList(L);
	DestoryList(L);
	return(0);
}

void MakeArray(int idx[],int age[],int len){
	int i;
	//printf("hu"); 
	for(i=0;i<len;i++){                                                   //数组赋值，输入值 
		printf("\nPlease input the idx and age of person %d\t\t",i+1);
		scanf("%d%d",&idx[i],&age[i]);
	}
	printf("The List you input is\nnumber  idx  age\n");
	for(i=0;i<len;i++){                                                 //数组打印，检查输入 
		printf("   %d    %3d  %3d\n",i,idx[i],age[i]);
	}
}
