/****************************************************

Name:              Graph.h
Auther:            Hawkeye
Date:            2018.11.18
Function:         �ڽӾ��� 

****************************************************/
//#include<queue> 
#include<iostream>
//#define INFINITY INT_MAX
#define INFINITY 999
using namespace std;
const int MAX_VERTEX_NUM = 20;
// ͼ�����ͣ�����ͼ��������������ͼ��������
//             0        1      2       3
typedef enum {DG, DN, UDG, UDN} GraphKind;
typedef int WeightType;
typedef char VertexType;
typedef int ArcType;
typedef struct {
	// VertexType��ʾ��������ͣ�����char��int����
	VertexType vexs[MAX_VERTEX_NUM];
	// ArcType��ʾ�ߺ�Ȩֵ������
	// ��Ϊ��Ȩͼ����ȡbool��
	// ��Ϊ������ȡint�͡�float�͡���
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
	//������������ 
	int kind;
	//GraphKind kind;
} MGraph;

int LocateVex(MGraph G, VertexType v) {
	//���Ҷ��� v ��ͼ G �еĴ洢λ�� 
	//��� G �д��ڶ��� v ������v ��λ���±꣬���򷵻�-1 
	for (int i=0; i<G.vexnum; i++)
		if (G.vexs[i] == v) return i;
	return -1;
}

void CreateUD(MGraph &G,int wkind) {
	//�Ӽ�������ͼ�Ķ��㼯�ͱ߼����������ڽӾ����ʾ������ͼ������ G
	//ʹ���ڽӾ�������
	printf("\nPlease input the number of node and the number of edge:\n");
	cin >> G.vexnum >> G.arcnum;             //���붥�����ͱ���
	//scanf("%d%d",&G.vexnum,&G.arcnum);
	int i,j,k;
	printf("\nPlease input the data of every node :\n");
	for (i=0; i<G.vexnum; i++)
		cin >> G.vexs[i]; // ���붥������
		//scanf("%c",&G.vexs[i]);
	for (i=0; i<G.vexnum; i++){
		for (j=0; j<G.vexnum; j++){
			if( wkind==2 ){
				G.arcs[i][j]=0;            //��ʼ���ڽӾ��� 
			}
			if( wkind==3 ){
				G.arcs[i][j] = INFINITY; // ���磬INFINITY=INT_MAX
			}
		}
	}
	for (k=0; k<G.arcnum; k++) {
		VertexType vi, vj;
		WeightType w;
		printf("\nPlease input every edge and weight(Only in net) :\n");
		if( wkind==2 ){
			cin >> vi >> vj;
			i = LocateVex(G, vi);
			j = LocateVex(G, vj);
			G.arcs[i][j] = G.arcs[j][i] = 1;
		}
		if( wkind==3 ){
			cin >> vi >> vj >> w;
			i = LocateVex(G, vi);
			j = LocateVex(G, vj);
			G.arcs[i][j] = G.arcs[j][i] = w;
		}
	}
}

//G.kind = UDN; // UDN��ʾ������
void CreateD(MGraph &G,int wkind) {
	//�Ӽ�������ͼ�Ķ��㼯�ͱ߼����������ڽӾ����ʾ���� G  
	//ʹ���ڽӾ������� 
	printf("\nPlease input the number of node and the number of edge :\n");
	cin >> G.vexnum >> G.arcnum ;             //���붥�����ͱ���
	int i,j,k;
	printf("\nPlease input the data of every node :\n");
	for (i=0; i<G.vexnum; i++) cin >> G.vexs[i]; // ���붥������
	for (i=0; i<G.vexnum; i++){
		for (j=0; j<G.vexnum; j++){
			if( wkind==0 ){
				G.arcs[i][j]=0;            //��ʼ���ڽӾ��� 
			}
			if( wkind==1 ){
				G.arcs[i][j] = INFINITY; // ���磬INFINITY=INT_MAX
			}
		}
	}
	for (k=0; k<G.arcnum; k++) {
		VertexType vi, vj;
		WeightType w;
		printf("\nPlease input every edge and weight(Only in net) :\n");
		if( wkind==0 ){
			cin >> vi >> vj;
			i = LocateVex(G, vi);
			j = LocateVex(G, vj);
			G.arcs[i][j] = 1;
		}
		if( wkind==1 ){
			cin >> vi >> vj >> w;
			i = LocateVex(G, vi);
			j = LocateVex(G, vj);
			G.arcs[i][j] = w;
		}
	}
}

//�����ݽṹ��Ӧ���㷨��page224
void InsertArc(MGraph &G,VertexType vi,VertexType vj){
	//��ͼ G �в��붥��vi ��vj �������ı߻�
	//�������������ͼ 
	int i,j;
	i=LocateVex(G,vi);           //�� vi ��λ���±� 
	j=LocateVex(G,vj);           //�� vj ��λ���±�
	if(i!=-1 && j!=-1){
		G.arcnum++;
		G.arcs[i][j]=1;
		if(G.kind==2)
			G.arcs[j][i]=1;
	}
}

int FirstAdjVex(MGraph G,int v){
	//��洢λ���±�Ϊ v �Ķ���ĵ�һ���ڽӵ� 
	//�������ڽӾ���� v ���ϵ�һ����0Ԫ���к� 
	//����� v ��û�з�0Ԫ�򷵻�-1
	int j;
	for(j=0;j<G.arcnum;j++)
		if(G.arcs[v][j]!=0)
			return j;
	return -1; 
}

int NextAdjVex(MGraph G,int v,int w){
	//��洢λ���±�Ϊ v �Ķ������һ���ڽӵ�
	//�������ڽӾ���� v �е� w ��֮����׸���0Ԫ���к�
	//��������������ķ�0Ԫ�򷵻�-1
	int j;
	for(j=w+1;j<G.arcnum;j++)
		if(G.arcs[v][j]!=0)
			return j;
	return -1; 
}
