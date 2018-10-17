#include <iostream>
using namespace std;

int Frequency(int n)
{
	if(n<=1)
	 return 2;
	return 2*Frequency(n-1);
}

int main()
{
	int n;
	cin>>n;
	cout<<Frequency(n)<<endl;
	return 0;
}