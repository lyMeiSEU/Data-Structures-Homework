
#include<stack>
#include<iostream>
using namespace std;

void pickfrom(int *Num, int i,int n) {
	int * temp = new int[n-1];
	for (int k = 0; k < i; ++k)
	{
		if (Num[k] != n)
			temp[k] = Num[k];
		else {
			for (int j = k+1; j < i; ++j)
				temp[j] = Num[j];
			break;
		}
	}
	delete[]Num;
	Num = new int[n - 1];
	for (int p = 0; p < n - 1; ++p)
		Num[p] = temp[p];
}
bool check(stack <int> leftstk, stack <int> downstk) //���˽���Ƿ����ʵ��
{
	if (leftstk.empty() == true)
		return true;
	else {
		while (!downstk.empty())
		{
			if (downstk.top() == leftstk.top())
			{
				leftstk.pop();
				return check(leftstk, leftstk);
			}
			downstk.pop();
		}
	}
	return false;
}

void coutall(int n, stack<int> stk, int *Num) //n!�����ö���ж��Ƿ����
{
	if (n <= 0) 
		if (check(stk, stk))
		{
			for (int j = 0; j < stk.size(); ++j)
			{
				cout << stk.top() << " ";
				stk.pop();
			}
			cout << endl;
		}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			stk.push(Num[i]);  //��ʣ���е�һ����ѹ��ջ
			pickfrom(Num, i, n); //ȡ����ѹ��ջ����
			coutall(n - 1, stk, Num);
		}
	}
}


int main()
{
	stack <int> leftstk;
	int n;
	cin >> n; //ջ��Ԫ�ظ���
	int *Num = new int[n];
	int i, j, k;
	for (i = 0; i < n; ++i)
		Num[i] = i;
	/*for (i = 0; i < n; ++i)
	{
		leftstk.push(n-i);
	}*/
	coutall(n, leftstk, Num);
	return 0;
}