#include<stdio.h>
#include<string.h>
int main()
{
	void get_next1(char *p,int next[]);
	int Find_KMP(char *s,char *p,int start,int next[]);
	void replace(char *s,char *b,int position,int lena);
	char s[80],a[80],b[80];
	char *p=s;
	int i,j,position,count=0;
	int next[40];
	printf("Please input main string s:\n");
	gets(s);
	printf("Please input find string a:\n");
	gets(a);
	get_next1(a,next);
	printf("next array is：\n"); 
	for(i=0;i<strlen(a);i++)
	  printf("%-3d",next[i]);
    //position=Find_KMP(s,a,0,next);
	//printf("起始位置为：\n");
	//printf("%d",position);
	while(strlen(p)>=strlen(a))
	{
      position=Find_KMP(p,a,0,next);
	  if(position==-1)
	  {
	  	//printf("not found!\n");
	  	break;
	  }
	  count++;
	  if(count==1)
	  {
	  	printf("First position is%d\n",position);
	  	printf("Please input the string you want replaceb:\n");
	  	gets(b);
	  }	
	 replace(p,b,position,strlen(a));
	 printf("After replace s is ---：\n");
	 puts(s);
	 p+=position+strlen(b);
	}
	if(count==0)
	printf("not found!");	  
	return 0;
}
void get_next1(char *p,int next[])
{
	int j=0,k=-1;
	next[0]=-1;
	while(j<=strlen(p)-1)
	  if(k==-1||p[j]==p[k])
	  {
	  	j++;
	  	k++;
	  	if(p[j]!=p[k]) next[j]=k;
	  	else next[j]=next[k];
	  }
	   else k=next[k];
}
int Find_KMP(char *s,char *p,int start,int next[])
{
	int i,j;
	if(start<0||start>strlen(s)-strlen(p))
	  printf("start值非法!\n");
	i=start;j=0;
	while(i<strlen(s)&&j<(int)strlen(p))
	  if(j==-1||s[i]==p[j])
	  {
	  	i++;
	  	j++;
	  }
	  else j=next[j];
	  if(j==strlen(p)) return(i-j);
	  return -1;
}
void replace(char *s,char *b,int position,int lena)
{
	int i,j,lens=strlen(s),lenb=strlen(b);
	if(lenb>lena)
	{
		for(i=lens+lenb-lena,j=lens;j>=position+lena;i--,j--)
		s[i]=s[j];
	}
	else if(lenb<lena)
	{
		for(i=position+lenb,j=position+lena;j<=lens;i++,j++)
		  s[i]=s[j];
	}
	i=0;
	while(b[i])
	{
		s[position++]=b[i++];
	}
}
