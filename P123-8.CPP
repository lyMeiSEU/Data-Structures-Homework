/*(a) 带状区域元素个数=n*n-((n-b)*(n-b)/2+(n-a)*(n-a)/2)*/

#include<iostream>
using namespace std;
/*(c)*/
int value(int n,int a,int b,int i,int j,int *c)
{
	
	if(i<=a&&j<b+i)
	{
		int sum=0;
		for(int p=0;p<b+i;++p)
			sum+=a+p;
		return sum;
	}
	
	else if(i>a&&i<n-b&&j>i-a&&j<i+b)
	{
		int sum=a*b+a*a/2+(i-a)*(a+b)+j-i+a;
		return sum;
	}
	else if(i>n-b&&j>a+n-1)
	{
		int sum=(n-a-b)*(b+a);
		for(int p=n-b;p<i;++p)
			sum+=a+n-i;
		return sum;
	}
	return 0;
}


int main()
{
	cout<<"输入n,a,b"<<endl;
	int n,a,b;
	cin>>n>>a>>b;
	int i,j;
	int **A=new int*[n];
	for(i=0;i<n;++i)
		A[i]=new int[n];
	cout<<"输入矩阵A"<<endl;
	for(i=0;i<n;++i)
		for(int j=0;j<n;++j)
			cin>>A[i][j];
	int *c=new int[(n*b+n*a)-(b*b+a*a)/2];
	int sum=0;
	for(i=0;i<n;++i)
	{

		if(i<=a)
		{
			for(j=0;j<b+i;++j)
				c[sum+j]=A[i][j];
			sum+=b+i;
		}
		
		else if(i>a&&i<n-b)
		{
			for(j=i-a;j<i+b;++j)
				c[sum+j-i+a]=A[i][j];
			sum+=b+a;
		}
		
		else
		{
			for(j=i-a;j<n;++j)
				c[sum+j-i+a]=A[i][j];
			sum+=n-i+a;
		}
	}
	cout<<"将A中非0元素储存到c得:"<<endl;
	for(i=0;i<(n*b+n*a)-(b*b+a*a)/2;++i)
		cout<<c[i]<<" ";
	cout<<endl;
	int iA,jA;
	cin>>iA>>jA;
	if(value(n,a,b,iA,jA,c)!=0)
	{
		cout<<"A["<<i<<","<<j<<"]为"<<"c中第"<<value(n,a,b,i,j,c)<<"个元素"<<endl;
	}
	else
		cout<<"A["<<i<<","<<j<<"]=0"<<endl;


	delete[]A;
	delete[]c;
	return 0;
}