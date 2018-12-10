
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=100001;
const int inf=1<<29;
int e,head[maxn],pnt[maxn],nxt[maxn];
int cnt_in[maxn],cnt_out[maxn];
bool vis[maxn];
int n,m,k;

void AddEdge(int u,int v)
{
    pnt[e]=v;nxt[e]=head[u];head[u]=e++;
}

void Topolterator(int v) {
	while (v--)
	{

		cin >> n >> m;
		e = 0;
		memset(head, -1, sizeof(head));
		memset(cnt_in, 0, sizeof(cnt_in));
		memset(cnt_out, 0, sizeof(cnt_out));
		memset(vis, 0, sizeof(vis));
		cout << "Input the edges.(Like <u,v>)" << endl;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			AddEdge(u, v);
			cnt_out[u]++;
			cnt_in[v]++;
		}
		int cnt = 0;
		int kj[maxn];
		while (1)
		{
			int f = 0;
			for (int u = 1; u <= n; u++)
			{
				if (cnt_in[u] == 0 && !vis[u])
				{
					f = 1;
					for (int i = head[u]; i != -1; i = nxt[i])
					{
						cnt_in[pnt[i]]--;
					}
					kj[cnt++] = u;
					vis[u] = 1;
				}
			}
			if (cnt == n || f == 0)
				break;
		}
		int k2 = 0;
		for (int i = 1; i <= n; i++)//如果所有的数字的入度都为0，代表这是一个无环图。
			if (vis[i] == 0)
				k2 = 1;
		if (k2 == 1)
			puts("Wrong");
		else
			puts("Correct");
		for (int i = 0; i < cnt; ++i) {
			cout << kj[i] << " ";
		}
	}
	
}
int main()
{
	cout << "Input the number of vertix" << endl;
    int v;
	cin >> v;
	Topolterator(v);
	
    return 0;
}
