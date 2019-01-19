/****************************************************

Name:            triangle.c
Auther:            Hawkeye
Date:           2018.9.25
Function:    Type number and print a YangHui triangle

****************************************************/

#include<stdio.h>
#include<math.h>

void main()
{
	short int a[100][100];
	short int m,i,j;
	printf("Please input a number as the area\n"); 
	scanf("%d",&m);
	printf("The area of YangHui triangle is %d\n",m); 
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			a[i][j]=0;
		}
	}
	for(i=0;i<m;i++){
		a[i][0]=1;
	}
	for(i=1;i<m;i++){
		for(j=1;j<m;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			//printf("1");
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<i+1;j++){
			printf("%3d%c",a[i][j],j-i?'  ':'\n');
			//printf("%3d",a[i][j]);
		}
	}
 } 
