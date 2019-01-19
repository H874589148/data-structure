/****************************************************

Name:           huffmanTree.cpp
Auther:            Hawkeye
Date:             2018.11.12
Function:  Huffman tree basic operation
			
			test:
			6 ���ַ� A,B,C,D,E,F �ڱ����г��ֵĴ����ֱ��ǣ�4,3,7,5,1,6��
			�� 110111101 ���н��룬���Ϊ ABF

****************************************************/

#include"huffman.h"

int main(){
	HuffmanTree HT;
	int i,len,Dlen,j=0;
	unsigned int *w;
	char * * HC;
	char *p;
	printf("Please input the length of your letters -----  "); //����һά��̬����
	scanf("%d",&len);
	//printf("Please input the weight of every letter -----  "); //����һά��̬����
	w=(unsigned int *)malloc((len+1)*sizeof(unsigned int));
	if(!w){
		printf("Memory size not enough!\n");
		exit(1);
	}
	for(i=1;i<=len;i++){                                        //���鸳ֵ������ֵ 
		printf("\nPlease input the weight of the %d letter '%c' :\t\t",i+1,64+i);
		scanf("%d",&w[i]);
	}
	printf("The weight list you input is\n\n");
	for(i=1;i<=len;i++){                                        //�����ӡ��������� 
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
	printf("Please input the length of letters you want decode -----  "); //����һά��̬����
	scanf("%d",&Dlen);
	//printf("Please input the weight of every letter -----  "); //����һά��̬����
	p=(char *)malloc((Dlen+1)*sizeof(char));
	p[Dlen]='\0';
	if(!p){
		printf("Memory size not enough!\n");
		exit(1);
	}
	getchar();													//���ջس� 
	printf("\nPlease input the letters you want decode ");
	for(i=0;i<Dlen;i++){                                        //���鸳ֵ������ֵ 
		scanf("%c",&p[i]);
	}
	printf("\nThe letters you input is\n\n");
	for(i=0;i<Dlen;i++){                                        //�����ӡ��������� 
		printf("%c",p[i]);
	}
	DeCode(HT,len,p);
	return 0;
}
