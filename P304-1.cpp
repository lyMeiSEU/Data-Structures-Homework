
#include<iostream>
#include <stdio.h>
using namespace std;
#define K 10
#define MAX 65535
#define MIN 0
int leaves[K + 1];
int successTree[K];
int loserTree[K];                 
void adjust(int i)
{
	int m, n;
	if (2 * i < K)               /* Get the Left Child */
		m = successTree[2 * i];
	else
		m = 2 * i - K + 1;
	if (2 * i + 1 < K)                 /* Get the Right Child */
		n = successTree[2 * i + 1];
	else
		n = 2 * i + -K + 2;
	successTree[i] = leaves[m] > leaves[n] ? n : m; /* Decide the winner */
}

void initTree()
{
	for (int i = 1; i < K + 1; i++)
		cin >> leaves[i];
	for (int i = K - 1; i > 0; i--)
		adjust(i);
}

void adjustloser(int i)
{
	int parent = (i + K - 1) / 2;      /* 求出父节点的下标 */
	while (parent > 0)
	{
		if (leaves[i] > leaves[loserTree[parent]])
		{
			int temp = loserTree[parent];
			loserTree[parent] = i;
			/* i指向的是优胜者 */
			i = temp;
		}
		parent = parent / 2;
	}
	loserTree[0] = i;
}
void initLoserTree()
{
	int i;
	for (i = 1; i < K + 1; i++)
		cin>>leaves[i];
	leaves[0] = MIN;
	for (int i = 0; i < K; i++)
		loserTree[i] = 0;
	for (int i = K; i > 0; i--)
		adjust(i);
}

void adjustToRoot(int i)
{
	int parent = (i + K - 1) / 2;

	while (parent > 0)
	{
		adjust(parent);
		parent = parent / 2;
	}
}

int main()
{
	cout << "Input the Nodes in the WinnerTrees (I define the node number is ten)." << endl;
	initTree();
	cout << "Input the Nodes in the LoserTrees (I define the node number is ten)." << endl;
	initLoserTree();
	cout << "We got the Winner tree: " << endl;
	for (int i = 1; i < K + 1; i++)      /* 每次用最大值替换掉冠军节点，并对树
								 * 进行调整,最终得到升序排序的序列 */
	{
		cout << leaves[successTree[1]] << " ";
		leaves[successTree[1]] = MAX;
		adjustToRoot(successTree[1]);
	}
	cout << endl;
	cout << "We got the Loser tree: " << endl;
	for (int i = 1; i < K + 1; i++)      /* 每次用最大值替换掉冠军节点，并对树
								 * 进行调整,最终得到升序排序的序列 */
	{
		cout << leaves[loserTree[1]] << " ";
		leaves[loserTree[1]] = MAX;
		adjustloser(loserTree[1]);
	}
	return 0;
}
