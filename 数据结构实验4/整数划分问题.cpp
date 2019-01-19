#include<stdio.h>

int cutway(int n,int m ){
	if(n<1||m<1) return 0;
	if((n==1)||(m==1)) return 1;
	if(n<m) return cutway(n,n);
	if(n==m) return cutway(n,m-1)+1;
	return cutway(n,m-1)+cutway(n-m,m);
}

int main(){
	int n;
	scanf("%d",&n);
	cutway(n,n);
	printf("%d\n",cutway(n,n));
}
