#include"Dijkstra.h"


//������������Ͷ�������ֵ�Ƿ���Ч�������Լ�����Ϊɶ��
//�������ͱ����Ĺ�ϵ�ǣ�((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge) {
    if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
        return false;
    return true;
}
int main() {
    int vexnum; int edge;

    cout << "����ͼ�Ķ�������ͱߵ�������" << endl;
    cin >> vexnum >> edge;
    while (!check(vexnum, edge)) {
        cout << "�������ֵ���Ϸ�������������" << endl;
        cin >> vexnum >> edge;
    }
    Graph_DG graph(vexnum, edge);
    graph.createGraph();
    graph.print();
    graph.Dijkstra(1);
    graph.print_path(1);
    system("pause");
    return 0;
}
/*
--------------------- 
���ߣ�Ouyang_Lianjun 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/qq_35644234/article/details/60870719 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�*/
