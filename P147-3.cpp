
#include<queue>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	queue<string> A;
	for (int i = 0; i < 100; ++i)
	{
		A.push(to_string(i));
	}
	cout << "The original queue A is:" << endl;
	queue<string> A1=A;
	for (int i = 0; i < 100; ++i)
	{
		cout<<A1.front()<<" ";
		A1.pop();
	}
	cout << endl;
	cout << "Pushing A into B,C..." << endl;
	queue<string> B, C;
	for (int j = 0; j < 100; ++j)
	{
		if (A.front().substr(0, 1) == "1")
		{
			B.push(A.front());
			A.pop();
		}
		else
		{
			C.push(A.front());
			A.pop();
		}
	}
	cout << "The sizes of queue B,C are" << endl;
	int Bs = B.size(), Cs = C.size();
	cout << "B: "<<B.size() <<" "<<"C: "<< C.size() << endl;
	cout << "B is:" << endl;
	for (int k = 0; k < Bs; ++k)
	{
		cout << B.front() << " ";
		B.pop();
	}
	cout << endl;
	cout << "C is:" << endl;
	for (int L = 0; L < Cs; ++L)
	{
		cout << C.front() << " ";
		C.pop();
	}
	return 0;
}