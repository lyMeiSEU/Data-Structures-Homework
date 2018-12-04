
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 11  //������������ֵ
#define MAXM 20  //�ߵĸ��������ֵ
using namespace std;

struct Edge  //��
{
	int begin, end, value; //�ߵĶ��㡢Ȩֵ
}edges[MAXM]; //�ߵ�����

int parent[MAXN];  //parent[i]Ϊ���� i ���ڼ��϶�Ӧ�����еĸ����
int vertex, edge;  //����������ߵĸ���
int i, j;  

void UFset()  //��ʼ��
{
	for (i = 1; i <= vertex; i++)
		parent[i] = -1;
}
int Find(int x) //���Ҳ����ؽڵ� x �������ϵĸ����
{
	int s; //����λ��
	for (s = x; parent[s] >= 0; s = parent[s]);
	while (s != x) //�Ż������Dѹ��·����ʹ�����Ĳ��Ҳ������١�
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}
//��������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ����������������Ԫ�ض���ͨ
void Union(int R1, int R2)
{
	int r1 = Find(R1), r2 = Find(R2); //r1 Ϊ R1 �ĸ���㣬r2 Ϊ R2 �ĸ����
	int tmp = parent[r1] + parent[r2]; //�������Ͻ�����֮��(����)
	//��� R2 ������������ > R1 ������������(ע�� parent[r1]�Ǹ���)
	if (parent[r1] > parent[r2]) //�Ż������D�D��Ȩ����
	{
		parent[r1] = r2;
		parent[r2] = tmp;
	}
	else
	{
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}
bool cmp(Edge a, Edge b) //ʵ�ִ�С��������ıȽϺ���
{
	return a.value <= b.value;
}
void Kruskal()
{
	int sumweight = 0;  //��������Ȩֵ
	int num = 0;  //��ѡ�õıߵ���Ŀ
	int u, v;  //ѡ�ñߵ���������
	UFset(); //��ʼ�� parent[]����
	for (i = 0; i < edge; i++)
	{
		u = edges[i].begin; v = edges[i].end;
		if (Find(u) != Find(v))
		{
			cout << u <<" "<< v <<" "<< edges[i].value << endl;
			sumweight += edges[i].value; num++;
			Union(u, v);
		}
		if (num >= vertex - 1) break;
	}
	cout << "Weight of MST is: " << sumweight << endl;
}
int main()
{
	int begin, end, value; //�ߵ������յ㼰Ȩֵ
	cout << "Input the number of Vertes and Edges" << endl;
	cin >> vertex >> edge;
	cout << "Input the begin and end of edge, Input the value of the edge" << endl;
	for (int i = 0; i < edge; i++)
	{
		cin>> begin >> end >> value; //����ߵ������յ�
		edges[i].begin = begin; edges[i].end = end; edges[i].value = value;
	}
	sort(edges, edges + edge, cmp);
	cout << endl;
	Kruskal();
	return 0;
}
