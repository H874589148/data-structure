/****************************************************

Name:              1.MST.h
Auther:            Hawkeye
Date:            2018.11.24
Function:   1.void bubbleSort(SqList&L);
			2.void selectSort(SqList&L);
			3.void quickSort(SqList&L,int start,int end);
			  int Partition(SqList&L,int start,int end);
test data: 6
		6 7 5 2 5 8
		9 4 1 3 15 13 10 11 12 16 14 0 6 10

****************************************************/

#define MAXSIZE 10
#include <stdio.h>
#include <time.h>
typedef int keytype; 
typedef char infotype;

typedef struct{
	keytype key;
	infotype otherinfo;
}RcdType;                //元素（记录）类型结构

typedef struct{
	RcdType r[MAXSIZE+1];//0单元不存放元素
	int len; 
}SqTable;                //待排序表结构

void swap(RcdType &a,RcdType &b){
	int t;
	t=a.key;
	a.key=b.key;
	b.key=t;
}

void BubSort(SqTable &L){ //对顺序表进行冒泡排序
	int i,j;
	for(i=1;i<L.len;i++){ //起泡第 i 个记录
		for(j=L.len;j>i;j--){
			if(L.r[j].key<L.r[j-1].key){
				swap(L.r[j],L.r[j-1]);
			}
		}
	}
}

void SelSort(SqTable &L){ //对顺序表进行选择排序
	int i,j,lowIndex;
	for(i=1;i<L.len;i++){ //选择第 i 个记录
		lowIndex=i;       //记录索引位置
		for(j=L.len;j>i;j--){//找最小值
			if(L.r[j].key<L.r[lowIndex].key){
				lowIndex=j;
			}
		}
		swap(L.r[i],L.r[lowIndex]);
	}
}

int Partition(SqTable &L,int low,int high){
	//对 L 顺序表，选取L.r[low] 作为轴值进行分割，并返回轴值位置
	int pivot;
	L.r[0]=L.r[low];                  //暂存轴值
	pivot=L.r[low].key;
	while(low<high){
		while(low<high && L.r[high].key>=pivot)
			high--;                   // high 向左移动
		L.r[low]=L.r[high];           //高端的小于轴值的元素移动到低端
		while(low<high && L.r[low].key<=pivot)
			low++;                    // low 向右移动
		L.r[high]=L.r[low];           //低端的大于轴值的元素移动到高端
	}
	L.r[low]=L.r[0];                  //放回轴值
	return low;
}

/*int FindPivot(SqTable &L,int i,int j){
	
	return ;
}

void QuiSort(SqTable &L,int i,int j){ //对顺序表进行快速排序
	int pivotIndex,k;
	pivotIndex=FindPivot(L,i,j);      // i,j 为子序列左右两端的下标
	swap(L.r[pivotIndex],L.r[j]);     //置轴点到末端
	//k=Partition(L,i,j,L.r[j].key);  //未使用此函数
	swap(L.r[k],L.r[j]);              //置轴点位置
	if((k-i)>1) QuiSort(L,i,k-1);     //左分区排序
	if((j-k)>1) QuiSort(L,k+1,j);     //右分区排序
}*/

void QSort(SqTable &L,int low,int high){
	//对 L.r[low..high]进行递归快速排序
	int pivotidx;
	if(low<high){                      //大于一个元素
		pivotidx=Partition(L,low,high);//分割为两部分
		QSort(L,low,pivotidx-1);       //递归快速排序 L.r[low,pivotidx-1]
		QSort(L,pivotidx+1,high);      //递归快速排序 L.r[low,pivotidx-1]
	}
}

void QuickSort(SqTable &L){
	//对 L 进行快速排序
	QSort(L,1,L.len);
}

int main(){
	int i;
	double start,finish;
	SqTable L,L1,L2;
	printf("\nPlease input the length of the list :\n");
	scanf("%d",&L.len);
	L1.len=L2.len=L.len;
	printf("\nPlease input the list you want to sort:\n");
	for(i=1;i<=L.len;i++){
		scanf("%d",&L.r[i].key);
		L1.r[i].key=L2.r[i].key=L.r[i].key;
	}
	//快速排序
	start=clock(); 
	QuickSort(L);
	finish=clock();
	printf("\nThe key word after quick sort is:\n");
	for(i=1;i<=L.len;i++){
		printf("%d ",L.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
	//冒泡排序 
	start=clock(); 
	BubSort(L1);
	finish=clock();
	printf("\nThe key word after bubble sort is:\n");
	for(i=1;i<=L1.len;i++){
		printf("%d ",L1.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
	printf("\nThe key word after select sort is:\n");
	//选择排序 
	start=clock(); 
	SelSort(L2);
	finish=clock();
	for(i=1;i<=L2.len;i++){
		printf("%d ",L2.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
}
