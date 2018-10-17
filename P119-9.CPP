/*Pat: a	b	c	a	b	c	a	c	a	b
	  -1   -1  -1	0	1	2	3  -1	0	1*/
	 #include<iostream>
	 using namespace std;
	 void FailureFunction(string pat,int *f)
	 {
		 int lengthP=pat.length();
		 f[0]=-1;
		 for(int i=0;i<lengthP;i++)//定f[i]
		 {
			 int nj=-1;
			 for(int j=0;j<i;j++)  //试取k
			 {
				 if(j==0&&pat[0]==pat[i])
				 {
					 nj=0;
					 continue;
				 }
				 for(int k=0;k<j;++k)//字符串比较
				 {
					 if(pat[k]!=pat[i-j+k])
						 break;
				 }
				 if(k==j)
					 nj=j-1;
			 }
			 f[i]=nj;
		 }
	 }

	int main()
	{
		string pat="abcabcacab";
		int *f=new int [pat.length()];
		FailureFunction(pat,f);
		for(int i=0;i<pat.length();++i)
			cout<<f[i]<<" ";
		cout<<endl;
		delete[]f;
		return 0;
	}

//当pat前后差别较大时，新故障函数计算时间可能多于原定故障函数

