#include<stack>
#include<iostream>
using namespace std;

int main()
{
	stack<int> stk;
	int i, j;
	int k = rand() % 100000;
	for (i = 0; i < k; ++i)
	{
		stk.push(rand() % 1000);
	}
	int size1 = stk.size();
	stack<int> stk1, stk2;
	int size3 = stk.size();
	for (j = 0; j < (size3 / 2)+1; ++j)
	{
		stk1.push(stk.top());
		stk.pop();
	}
	for (j = 0; j < size3 / 2; ++j)
	{
		stk1.push(stk.top());
		stk.pop();
	}
	stack<int> newstk;
	
	while(!stk1.empty())
	{
		newstk.push(stk1.top());
		stk1.pop();
	}
	while(!stk2.empty())
	{
		newstk.push(stk2.top());
		stk2.pop();
	}
	int size2 = newstk.size();
	cout << size1 << " " << size2 << endl;
	return 0;
}