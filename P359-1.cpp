
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAXN 11  //顶点个数的最大值
#define MAXM 20  //边的个数的最大值
using namespace std;

struct Edge  //边
{
	int begin, end, value; //边的顶点、权值
}edges[MAXM]; //边的数组

int parent[MAXN];  //parent[i]为顶点 i 所在集合对应的树中的根结点
int vertex, edge;  //顶点个数、边的个数
int i, j;  

void UFset()  //初始化
{
	for (i = 1; i <= vertex; i++)
		parent[i] = -1;
}
int Find(int x) //查找并返回节点 x 所属集合的根结点
{
	int s; //查找位置
	for (s = x; parent[s] >= 0; s = parent[s]);
	while (s != x) //优化方案―压缩路径，使后续的查找操作加速。
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}
//将两个不同集合的元素进行合并，使两个集合中任两个元素都连通
void Union(int R1, int R2)
{
	int r1 = Find(R1), r2 = Find(R2); //r1 为 R1 的根结点，r2 为 R2 的根结点
	int tmp = parent[r1] + parent[r2]; //两个集合结点个数之和(负数)
	//如果 R2 所在树结点个数 > R1 所在树结点个数(注意 parent[r1]是负数)
	if (parent[r1] > parent[r2]) //优化方案――加权法则
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
bool cmp(Edge a, Edge b) //实现从小到大排序的比较函数
{
	return a.value <= b.value;
}
void Kruskal()
{
	int sumweight = 0;  //生成树的权值
	int num = 0;  //已选用的边的数目
	int u, v;  //选用边的两个顶点
	UFset(); //初始化 parent[]数组
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
	int begin, end, value; //边的起点和终点及权值
	cout << "Input the number of Vertes and Edges" << endl;
	cin >> vertex >> edge;
	cout << "Input the begin and end of edge, Input the value of the edge" << endl;
	for (int i = 0; i < edge; i++)
	{
		cin>> begin >> end >> value; //读入边的起点和终点
		edges[i].begin = begin; edges[i].end = end; edges[i].value = value;
	}
	sort(edges, edges + edge, cmp);
	cout << endl;
	Kruskal();
	return 0;
}
