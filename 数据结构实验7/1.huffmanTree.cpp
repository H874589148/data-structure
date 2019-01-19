/****************************************************

Name:           huffmanTree.cpp
Auther:            Hawkeye
Date:             2018.11.12
Function:  Huffman tree basic operation
			
			test:
			6 种字符 A,B,C,D,E,F 在报文中出现的次数分别是：4,3,7,5,1,6。
			对 110111101 进行解码，结果为 ABF

****************************************************/

#include"huffman.h"

int main(){
	HuffmanTree HT;
	int i,len,Dlen,j=0;
	unsigned int *w;
	char * * HC;
	char *p;
	printf("Please input the length of your letters -----  "); //建立一维动态数组
	scanf("%d",&len);
	//printf("Please input the weight of every letter -----  "); //建立一维动态数组
	w=(unsigned int *)malloc((len+1)*sizeof(unsigned int));
	if(!w){
		printf("Memory size not enough!\n");
		exit(1);
	}
	for(i=1;i<=len;i++){                                        //数组赋值，输入值 
		printf("\nPlease input the weight of the %d letter '%c' :\t\t",i+1,64+i);
		scanf("%d",&w[i]);
	}
	printf("The weight list you input is\n\n");
	for(i=1;i<=len;i++){                                        //数组打印，检查输入 
		printf("   %c    %3d\n",64+i,w[i]);
	}
	SetHuffmanTree(HT,w,len);
	//printf("win");
	HuffmanCoding(HT,HC,len);
	/*for(i=0;i<=len;j++){
		if(HC[j]!='\0'){
			printf("%c",HC[j]);
		}
		if(HC[j]=='\0'){
			printf("\n");
			i++;
		}
	}*/
	for(i=1;i<=len;i++){
		printf("%s\n",HC[i]);
	}
	printf("Please input the length of letters you want decode -----  "); //建立一维动态数组
	scanf("%d",&Dlen);
	//printf("Please input the weight of every letter -----  "); //建立一维动态数组
	p=(char *)malloc((Dlen+1)*sizeof(char));
	p[Dlen]='\0';
	if(!p){
		printf("Memory size not enough!\n");
		exit(1);
	}
	getchar();													//吸收回车 
	printf("\nPlease input the letters you want decode ");
	for(i=0;i<Dlen;i++){                                        //数组赋值，输入值 
		scanf("%c",&p[i]);
	}
	printf("\nThe letters you input is\n\n");
	for(i=0;i<Dlen;i++){                                        //数组打印，检查输入 
		printf("%c",p[i]);
	}
	DeCode(HT,len,p);
	return 0;
}
