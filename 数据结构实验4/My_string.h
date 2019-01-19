#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<memory>
//#include"kmp.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define NOTFOUND -2
#define MAX_LEN 255                                                   //每次读入的字符串的最大长度
#define MAXCMD 20                                                     //每个命令的最大长度
#define MAXN 10                                                       //字符串的最大个数

typedef struct string
{
    char *ch;                                                         //若是非空串，则按串长分配储存区，否则ch为NULL
    int length;                                                       //串长度
}String,*Mystr;

//串 
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
	//在串S中从start位置开始，查找第一次出现模式P的位置并返回，没找到返回NOTFOUND即-2 
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
	//求模式串P的next 函数修正值并写入数组next[]
	int j,k;
	j=0;
	k=-1;
	next[0] =-1;
	//P.length=5;
	while(j<=P.length-1)
		if(k==-1 || *(P.ch+j)==*(P.ch+k)){
			j++;
			k++;
			if(*(P.ch+j)!=*(P.ch+k)) next[j]=k;         //P[j]!=P[k]时才赋值为k
			else next[j]=next[k]; 
		}
		else k=next[k];
}


/****************************************************

Name:            My_string.h
Auther:            Hawkeye
Date:           2018.10.22
Function:      write  StrAssign(), StrCopy() , StrLenth() , StrCompare() , StrConcat() , Substring(), Replace(),
            complete     串赋值,    串复制,    求串长度,      串比较,        串连接,      求字串,     子串替代    等相应功能。

           注:Replace() 依赖 Find_KMP()

****************************************************/

int StrAssign(String &T,char chars[])                                      //把字符串常量 chars 赋给T 
{
	//printf("Come in successfully");
	//if (T.ch) free(T.ch);
	int i,len;
	//printf("cut here");
	for (len=0;chars[len]!='\0';len++);{                                   //计算chars的长度存入len
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

int StrCopy(String &T,String S){                                       //串 S 复制到串 T 
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

int StrLength(String T)                                                //求字符串长度 
{
	return T.length;
}

int StrCompare(String T,String S)                                      //比较串 S 、 T 的长度 
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
int StrConcat(String &T,String S1,String S2)                           // S1 、 S2连接成新串并用 T 返回 
{
	if (T.ch) free(T.ch);
	
	if (!(T.ch=(char*)malloc(sizeof(char)*(S1.length+S2.length)))) return OVERFLOW;

	int i;
	for (i=0;i<S1.length;i++)   //将串S1先放在T.ch的前面部分
		*(T.ch+i)=*(S1.ch+i);
	for (i=0;i<S2.length+1;i++)   //将串S2接在后面
		*(T.ch+i+S1.length)=*(S2.ch+i);
	T.length=S1.length+S2.length;

	return OK;
}

int Substring(String &T,String S,int pos,int len)                      //用 T 返回串 S 中位置是 pos 、 长度是 len 的子串 
{
	if (pos<0 || pos>=S.length || len<0 || pos+len-1>S.length-1) return ERROR;  //输入数据不合法

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
    if (pos>T.length-1) return ERROR;   //输入数据不合法
   
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
        if (!S1[j]) return i;                                    //表示已经找到可行的起始位置
    }
    return NOTFOUND;                                             //没有找到可行的起始位置，返回-1
}
*/

int StrReplace(String &T,String S2,String S1,int next[])     //将 T 中 S1 替换为 S2 
{
    int pos,i,len1,len2;
 
    //for (len1=0;S1[len1];len1++);
	len1=S1.length;                                //计算串S1的长度
    //for (len2=0;S2[len2];len2++);
	len2=S2.length;                                //计算串S2的长度
 
    while (1)                                                    //判断T串中是否存在串S1
    {
        pos=Find_KMP(T,S1,0,next);
		//StrFind(T,S1);
		//printf("pos = %d",pos);
        pos++;
		if (pos==NOTFOUND) return NOTFOUND;break;
 
        if (len1==len2)                                          //当串S1与串S2一样长时，可以直接替换
        {
            for (i=pos;i<pos+len1;i++)
                *(T.ch+i)=*(S2.ch+i-pos);
        }
        else if (len1<len2)     //当串S2的长度大于串S1时，先将T串的S1串后面的串往后移，然后将S2串覆盖T串中S1串
        {
            if (!(T.ch=(char*)malloc((T.length+len2-len1)*sizeof(char)))) return OVERFLOW;
            for (i=T.length-1;i>=pos+len1;i--) *(T.ch+i+len2-len1)=*(T.ch+i);
            for (i=pos;i<pos+len2;i++) *(T.ch+i)=*(S2.ch+i-pos);
            T.length+=len2-len1;
        }
        else if (len1>len2)     //当串S2小于串S1时，先将T串的S1串后面的串往前移，返回将S2串覆盖T串中的S1串
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
