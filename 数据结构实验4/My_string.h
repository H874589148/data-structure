#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<memory>
//#include"kmp.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define NOTFOUND -2
#define MAX_LEN 255                                                   //ÿ�ζ�����ַ�������󳤶�
#define MAXCMD 20                                                     //ÿ���������󳤶�
#define MAXN 10                                                       //�ַ�����������

typedef struct string
{
    char *ch;                                                         //���Ƿǿմ����򰴴������䴢����������chΪNULL
    int length;                                                       //������
}String,*Mystr;

//�� 
/*
typedef unsigned char SString[MAX_LEN+1]
or
typedef char SString[MAX_LEN+1]
or
chap * p = new char[]*/


/****************************************************

Name:               kmp.h
Auther:            Hawkeye
Date:            2018.10.24
Function:           KMP

****************************************************/

int Find_KMP(String S,String P,int start,int next[])
{
	//�ڴ�S�д�startλ�ÿ�ʼ�����ҵ�һ�γ���ģʽP��λ�ò����أ�û�ҵ�����NOTFOUND��-2 
	if(start<0 || start>(S.length-P.length))
		{
			printf("Error!");
			return NOTFOUND;
		 } 
	int i,j;//next[P.length];
	i=start;
	j=0;
	while(i<S.length && j<P.length)
		if(j==-1 || *(S.ch+i)==*(P.ch+j)){
			i++;
			j++;
		}
		else j=next[j];
		if(j==P.length) return (i-j);
		return NOTFOUND;
}

int get_next1(String &P,int next[])
{
	//��ģʽ��P��next ��������ֵ��д������next[]
	int j,k;
	j=0;
	k=-1;
	next[0] =-1;
	//P.length=5;
	while(j<=P.length-1)
		if(k==-1 || *(P.ch+j)==*(P.ch+k)){
			j++;
			k++;
			if(*(P.ch+j)!=*(P.ch+k)) next[j]=k;         //P[j]!=P[k]ʱ�Ÿ�ֵΪk
			else next[j]=next[k]; 
		}
		else k=next[k];
}


/****************************************************

Name:            My_string.h
Auther:            Hawkeye
Date:           2018.10.22
Function:      write  StrAssign(), StrCopy() , StrLenth() , StrCompare() , StrConcat() , Substring(), Replace(),
            complete     ����ֵ,    ������,    �󴮳���,      ���Ƚ�,        ������,      ���ִ�,     �Ӵ����    ����Ӧ���ܡ�

           ע:Replace() ���� Find_KMP()

****************************************************/

int StrAssign(String &T,char chars[])                                      //���ַ������� chars ����T 
{
	//printf("Come in successfully");
	//if (T.ch) free(T.ch);
	int i,len;
	//printf("cut here");
	for (len=0;chars[len]!='\0';len++);{                                   //����chars�ĳ��ȴ���len
		//printf("len=%d",len); 
		;
	}
	if (!len)
    {
		T.ch=NULL;
		T.length=0;
    }
	else
	{
		if (!(T.ch=(char*)malloc((len+1)*sizeof(char)))) return OVERFLOW;
		memset(T.ch,0,len*sizeof(char));
		for (i=0;i<len+1;i++) *(T.ch+i)=chars[i];
		printf("Create string is\n");
		for (i=0;i<len;i++) printf("%c",*(T.ch+i));
		T.length=len;
	}
	return OK;
}

int StrCopy(String &T,String S){                                       //�� S ���Ƶ��� T 
	int i;
	//printf("begin");
	if (!(T.ch=(char*)malloc(S.length*sizeof(char)))) return OVERFLOW;
	for(i=0;i<=S.length;i++){
		*(T.ch+i)=*(S.ch+i);
	}
	T.length=S.length;
	//printf("copy"); 
	return OK;
}

int StrLength(String T)                                                //���ַ������� 
{
	return T.length;
}

int StrCompare(String T,String S)                                      //�Ƚϴ� S �� T �ĳ��� 
{
	int i;
	for (i=0;i<S.length && i<T.length;i++)
		if (*(T.ch+i)!=*(S.ch+i)) return *(T.ch+i)>*(S.ch+i)?1:-1;
	return T.length-S.length;
}
/*
int StrClear(String &T)
{
	if (T.ch) {free(T.ch); T.ch=NULL;}
	T.length=0;
	return OK;
}
*/
int StrConcat(String &T,String S1,String S2)                           // S1 �� S2���ӳ��´����� T ���� 
{
	if (T.ch) free(T.ch);
	
	if (!(T.ch=(char*)malloc(sizeof(char)*(S1.length+S2.length)))) return OVERFLOW;

	int i;
	for (i=0;i<S1.length;i++)   //����S1�ȷ���T.ch��ǰ�沿��
		*(T.ch+i)=*(S1.ch+i);
	for (i=0;i<S2.length+1;i++)   //����S2���ں���
		*(T.ch+i+S1.length)=*(S2.ch+i);
	T.length=S1.length+S2.length;

	return OK;
}

int Substring(String &T,String S,int pos,int len)                      //�� T ���ش� S ��λ���� pos �� ������ len ���Ӵ� 
{
	if (pos<0 || pos>=S.length || len<0 || pos+len-1>S.length-1) return ERROR;  //�������ݲ��Ϸ�

	//if (T.ch)
	free(T.ch);
	
	if (!len)
	{
		T.ch=NULL;
		T.length=0;
	}
	else
	{
		if (!(T.ch=(char*)malloc(len*sizeof(char)))) return OVERFLOW;
		int i;
		for (i=0;i<len;i++)
			*(T.ch+i)=*(S.ch+pos+i);
		T.length=len;
	}


	return OK;
}
/*
int StrCover(String &T,int pos,char *chars)
{
    if (pos>T.length-1) return ERROR;   //�������ݲ��Ϸ�
   
    int i,len;
    for (len=0;chars[len];len++);
 
    if (pos+len-1>T.length-1)
        if (!(T.ch=(char*)realloc(T.ch,(pos+len)*sizeof(char)))) return OVERFLOW;
        else T.length=pos+len;
 
    for (i=0;i<len;i++) T.ch[pos+i]=chars[i];
   
    return OK;
}

int StrFind(String T,char *S1)
{
    int i,j;
    for (i=0;i<T.length;i++)
    {
        for (j=0;i+j<T.length && S1[j];j++)
            if (T.ch[i+j]!=S1[j]) break;
        if (!S1[j]) return i;                                    //��ʾ�Ѿ��ҵ����е���ʼλ��
    }
    return NOTFOUND;                                             //û���ҵ����е���ʼλ�ã�����-1
}
*/

int StrReplace(String &T,String S2,String S1,int next[])     //�� T �� S1 �滻Ϊ S2 
{
    int pos,i,len1,len2;
 
    //for (len1=0;S1[len1];len1++);
	len1=S1.length;                                //���㴮S1�ĳ���
    //for (len2=0;S2[len2];len2++);
	len2=S2.length;                                //���㴮S2�ĳ���
 
    while (1)                                                    //�ж�T�����Ƿ���ڴ�S1
    {
        pos=Find_KMP(T,S1,0,next);
		//StrFind(T,S1);
		//printf("pos = %d",pos);
        pos++;
		if (pos==NOTFOUND) return NOTFOUND;break;
 
        if (len1==len2)                                          //����S1�봮S2һ����ʱ������ֱ���滻
        {
            for (i=pos;i<pos+len1;i++)
                *(T.ch+i)=*(S2.ch+i-pos);
        }
        else if (len1<len2)     //����S2�ĳ��ȴ��ڴ�S1ʱ���Ƚ�T����S1������Ĵ������ƣ�Ȼ��S2������T����S1��
        {
            if (!(T.ch=(char*)malloc((T.length+len2-len1)*sizeof(char)))) return OVERFLOW;
            for (i=T.length-1;i>=pos+len1;i--) *(T.ch+i+len2-len1)=*(T.ch+i);
            for (i=pos;i<pos+len2;i++) *(T.ch+i)=*(S2.ch+i-pos);
            T.length+=len2-len1;
        }
        else if (len1>len2)     //����S2С�ڴ�S1ʱ���Ƚ�T����S1������Ĵ���ǰ�ƣ����ؽ�S2������T���е�S1��
        {
            for (i=pos+len1;i<T.length;i++) *(T.ch+i-len1+len2)=*(T.ch+i);
            for (i=pos;i<pos+len2;i++) *(T.ch+i)=*(S2.ch+i-pos);
            T.length-=len1-len2;
        }
    }
 
    return OK;
}

/*
int StrPrint(String T)
{
    int i;
    if (T.length)
    {
        for (i=0;i<T.length;i++) printf("%c",T.ch[i]);
        printf("\n");
    }
    else printf("Nothing to Print.\n");
    return OK;
}

int CharsCompare(char *T,char *S)
{
    int i;
    for (i=0;T[i] && S[i];i++)
        if (T[i]!=S[i]) return T[i]>S[i]?1:-1;
    return T[i]?1:0;
}
*/
