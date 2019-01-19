/****************************************************

Name:              Graph.h
Auther:            Hawkeye
Date:            2018.11.18
Function:         邻接矩阵 

****************************************************/
//#include<queue> 
#include<iostream>
//#define INFINITY INT_MAX
#define INFINITY 999
using namespace std;
const int MAX_VERTEX_NUM = 20;
// 图的类型：有向图、有向网、无向图、无向网
//             0        1      2       3
typedef enum {DG, DN, UDG, UDN} GraphKind;
typedef int WeightType;
typedef char VertexType;
typedef int ArcType;
typedef struct {
	// VertexType表示顶点的类型，例如char、int……
	VertexType vexs[MAX_VERTEX_NUM];
	// ArcType表示边和权值的类型
	// 若为无权图，可取bool型
	// 若为网，可取int型、float型……
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;
	//顶点数，边数 
	int kind;
	//GraphKind kind;
} MGraph;

int LocateVex(MGraph G, VertexType v) {
	//查找顶点 v 在图 G 中的存储位置 
	//如果 G 中存在顶点 v ，返回v 的位置下标，否则返回-1 
	for (int i=0; i<G.vexnum; i++)
		if (G.vexs[i] == v) return i;
	return -1;
}

void CreateUD(MGraph &G,int wkind) {
	//从键盘输入图的顶点集和边集，创建用邻接矩阵表示的有向图或者网 G
	//使用邻接矩阵构造网
	printf("\nPlease input the number of node and the number of edge:\n");
	cin >> G.vexnum >> G.arcnum;             //读入顶点数和边数
	//scanf("%d%d",&G.vexnum,&G.arcnum);
	int i,j,k;
	printf("\nPlease input the data of every node :\n");
	for (i=0; i<G.vexnum; i++)
		cin >> G.vexs[i]; // 读入顶点数据
		//scanf("%c",&G.vexs[i]);
	for (i=0; i<G.vexnum; i++){
		for (j=0; j<G.vexnum; j++){
			if( wkind==2 ){
				G.arcs[i][j]=0;            //初始化邻接矩阵 
			}
			if( wkind==3 ){
				G.arcs[i][j] = INFINITY; // 例如，INFINITY=INT_MAX
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

//G.kind = UDN; // UDN表示无向网
void CreateD(MGraph &G,int wkind) {
	//从键盘输入图的顶点集和边集，创建用邻接矩阵表示的网 G  
	//使用邻接矩阵构造网 
	printf("\nPlease input the number of node and the number of edge :\n");
	cin >> G.vexnum >> G.arcnum ;             //读入顶点数和边数
	int i,j,k;
	printf("\nPlease input the data of every node :\n");
	for (i=0; i<G.vexnum; i++) cin >> G.vexs[i]; // 读入顶点数据
	for (i=0; i<G.vexnum; i++){
		for (j=0; j<G.vexnum; j++){
			if( wkind==0 ){
				G.arcs[i][j]=0;            //初始化邻接矩阵 
			}
			if( wkind==1 ){
				G.arcs[i][j] = INFINITY; // 例如，INFINITY=INT_MAX
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

//《数据结构及应用算法》page224
void InsertArc(MGraph &G,VertexType vi,VertexType vj){
	//在图 G 中插入顶点vi 和vj 所关联的边或弧
	//包含有向和无向图 
	int i,j;
	i=LocateVex(G,vi);           //求 vi 的位置下标 
	j=LocateVex(G,vj);           //求 vj 的位置下标
	if(i!=-1 && j!=-1){
		G.arcnum++;
		G.arcs[i][j]=1;
		if(G.kind==2)
			G.arcs[j][i]=1;
	}
}

int FirstAdjVex(MGraph G,int v){
	//求存储位置下标为 v 的顶点的第一个邻接点 
	//即：求邻接矩阵第 v 行上第一个非0元的列号 
	//如果第 v 行没有非0元则返回-1
	int j;
	for(j=0;j<G.arcnum;j++)
		if(G.arcs[v][j]!=0)
			return j;
	return -1; 
}

int NextAdjVex(MGraph G,int v,int w){
	//求存储位置下标为 v 的顶点的下一个邻接点
	//即：求邻接矩阵第 v 行第 w 列之后的首个非0元的列号
	//如果不存在这样的非0元则返回-1
	int j;
	for(j=w+1;j<G.arcnum;j++)
		if(G.arcs[v][j]!=0)
			return j;
	return -1; 
}
