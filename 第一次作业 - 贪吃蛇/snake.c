/**********************************************************************

date:2018/9/20
author:hawkeye

**********************************************************************/


#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
//#include <unistd.h>
#include <conio.h>
#include <string.h>
#include <time.h>


int map[30][30];      /*����һ����ά����
                       �������0ʱ��Ϊ�հף�
					   �������1ʱ��Ϊ�߿�
					   �������2ʱ��Ϊ����
					   �������3ʱ��Ϊ���*/

struct snake         //������������Ľṹ��
{
	int x;
	int y;
	struct snake *next;
 } ;
 
struct snake* creatlist()     //����ͷ�巨�������� 
{
	int i;
	struct snake*head;
	struct snake*tail;
	tail=(struct snake*)malloc(sizeof(struct snake));
	tail->next=NULL;
	tail->x=15;
	tail->y=15;
	for(i=0;i<3;i++)
	{
		head==(struct snake*)malloc(sizeof(struct snake));
		head->x=tail->x-1;
		head->y=tail->y;
		head->next=tail;
		tail=head;
	}
};

/*loop:   srand(time(NULL));     //����ʳ��
		i=rand()%28;
		i+=2;
		j=rand()%29;
		j+=2;
	if(map[i][j]==1|map[i][j]==2)
		goto loop; */
void loop(){
	int i,j;
	srand(time(NULL));     //����ʳ��
		i=rand()%28;
		i+=2;
		j=rand()%29;
		j+=2;
	if(map[i][j]==1|map[i][j]==2)
		goto loop(); 
}
		
int eatself(int n)            //�ж��Ƿ�ҧ���Լ� 
{
	struct snake *p;
	struct snake *head;
	int i;
	p=(struct snake*)malloc(sizeof(struct snake));
	p=head->next;
	for(i=1;i<n;i++)
	{
		if(head->x==p->x&&head->y==p->y)
		{
			end=1;
			break;
		}
		p=p->next;
	}
	return end;
}

struct back*cantback(int n)          //�߲��ܻ�ͷ 
{
	switch(n)
	{
		case 0:
			if(k==1)
				n=1;
			break;
		case 1:
			if(k==0)
				n=0;
			break;
		case 2:
			if(k==3)
				n=3;
			break;
		case 3:
			if(k==2)
				n=2;
			break;
	}
	k=n;
	return n;
}

int printall(int a[30][31])            //������ж��� 
{
	int i,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<31;j++)
		{
			if(a[i][j]==1|a[i][j]==2|a[i][j]==3)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
}
