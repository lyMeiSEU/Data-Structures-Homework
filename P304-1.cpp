
#include<iostream>
#include <stdio.h>
using namespace std;
#define K 10
#define MAX 65535
int leaves[K + 1];
int successTree[K];

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
		cin>>leaves[i];
	for (int i = K - 1; i > 0; i--)
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
	cout << "Input the Nodes in the Trees (I define the node number is ten)." << endl;
	initTree();
	for (int i = 1; i < K + 1; i++)      /* 每次用最大值替换掉冠军节点，并对树
								 * 进行调整,最终得到升序排序的序列 */
	{
		cout<< leaves[successTree[1]] <<" ";
		leaves[successTree[1]] = MAX;
		adjustToRoot(successTree[1]);
	}
	return 0;
}
