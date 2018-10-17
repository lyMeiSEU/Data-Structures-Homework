#include <iostream>
using namespace std;

int N;

int Factorial(int N,int n)
{
	if(N<=n)
		return 1;
	return N*Factorial(N-1,n);
}

int Recursive(int n)
{
	if(n<=0)
		return 1;
	if(n==N)
		return 1+Recursive(n-1);
	else
		return (Factorial(N,n)/(N-n))+Recursive(n-1);
}

int main()
{
	
	cin>>N;
	cout<<Recursive(N)<<endl;
}