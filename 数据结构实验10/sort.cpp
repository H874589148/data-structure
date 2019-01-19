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
}RcdType;                //Ԫ�أ���¼�����ͽṹ

typedef struct{
	RcdType r[MAXSIZE+1];//0��Ԫ�����Ԫ��
	int len; 
}SqTable;                //�������ṹ

void swap(RcdType &a,RcdType &b){
	int t;
	t=a.key;
	a.key=b.key;
	b.key=t;
}

void BubSort(SqTable &L){ //��˳������ð������
	int i,j;
	for(i=1;i<L.len;i++){ //���ݵ� i ����¼
		for(j=L.len;j>i;j--){
			if(L.r[j].key<L.r[j-1].key){
				swap(L.r[j],L.r[j-1]);
			}
		}
	}
}

void SelSort(SqTable &L){ //��˳������ѡ������
	int i,j,lowIndex;
	for(i=1;i<L.len;i++){ //ѡ��� i ����¼
		lowIndex=i;       //��¼����λ��
		for(j=L.len;j>i;j--){//����Сֵ
			if(L.r[j].key<L.r[lowIndex].key){
				lowIndex=j;
			}
		}
		swap(L.r[i],L.r[lowIndex]);
	}
}

int Partition(SqTable &L,int low,int high){
	//�� L ˳���ѡȡL.r[low] ��Ϊ��ֵ���зָ��������ֵλ��
	int pivot;
	L.r[0]=L.r[low];                  //�ݴ���ֵ
	pivot=L.r[low].key;
	while(low<high){
		while(low<high && L.r[high].key>=pivot)
			high--;                   // high �����ƶ�
		L.r[low]=L.r[high];           //�߶˵�С����ֵ��Ԫ���ƶ����Ͷ�
		while(low<high && L.r[low].key<=pivot)
			low++;                    // low �����ƶ�
		L.r[high]=L.r[low];           //�Ͷ˵Ĵ�����ֵ��Ԫ���ƶ����߶�
	}
	L.r[low]=L.r[0];                  //�Ż���ֵ
	return low;
}

/*int FindPivot(SqTable &L,int i,int j){
	
	return ;
}

void QuiSort(SqTable &L,int i,int j){ //��˳�����п�������
	int pivotIndex,k;
	pivotIndex=FindPivot(L,i,j);      // i,j Ϊ�������������˵��±�
	swap(L.r[pivotIndex],L.r[j]);     //����㵽ĩ��
	//k=Partition(L,i,j,L.r[j].key);  //δʹ�ô˺���
	swap(L.r[k],L.r[j]);              //�����λ��
	if((k-i)>1) QuiSort(L,i,k-1);     //���������
	if((j-k)>1) QuiSort(L,k+1,j);     //�ҷ�������
}*/

void QSort(SqTable &L,int low,int high){
	//�� L.r[low..high]���еݹ��������
	int pivotidx;
	if(low<high){                      //����һ��Ԫ��
		pivotidx=Partition(L,low,high);//�ָ�Ϊ������
		QSort(L,low,pivotidx-1);       //�ݹ�������� L.r[low,pivotidx-1]
		QSort(L,pivotidx+1,high);      //�ݹ�������� L.r[low,pivotidx-1]
	}
}

void QuickSort(SqTable &L){
	//�� L ���п�������
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
	//��������
	start=clock(); 
	QuickSort(L);
	finish=clock();
	printf("\nThe key word after quick sort is:\n");
	for(i=1;i<=L.len;i++){
		printf("%d ",L.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
	//ð������ 
	start=clock(); 
	BubSort(L1);
	finish=clock();
	printf("\nThe key word after bubble sort is:\n");
	for(i=1;i<=L1.len;i++){
		printf("%d ",L1.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
	printf("\nThe key word after select sort is:\n");
	//ѡ������ 
	start=clock(); 
	SelSort(L2);
	finish=clock();
	for(i=1;i<=L2.len;i++){
		printf("%d ",L2.r[i].key);
	}
	//printf("\n\n%f seconds\n",(finish-start)/CLOCKS_PER_SEC);
}
