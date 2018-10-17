#include<iostream>
using namespace std;

int OrderedList(int a[],int b[],int n,int m)
{
	int i;
	long int acounter=0,bcounter=0;
	for(i=0;i<n;++i)
	{
		acounter+=a[i];
	}
	for(i=0;i<m;++i)
	{
		bcounter+=b[i];
	}
	if(acounter==bcounter)
		return 0;
	else if(acounter>bcounter)
		return 1;
	else 
		return -1;
}

int main()
{
	int a[]={1,2,3,4,5,6,7,8,9},b[]={2,3,4,5,6,7,8,9,10};

	cout<<OrderedList(a,b,9,9)<<endl;
	return 0;
}