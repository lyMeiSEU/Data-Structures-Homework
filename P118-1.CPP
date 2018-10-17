#include<iostream>
using namespace std;

void string_frequency(char *str)
{
	char ch[2][100]={0};
	int i,j;
	ch[0][0]=127;
	for(i=0;str[i]!='\0';i++)
	{
		for(j=0;ch[0][j]!='\0';j++)
			if(str[i]==ch[0][j])
			{
				ch[1][j]++;
				break;
			}
			if(ch[0][j]==0)
			{
				ch[0][j]=str[i];
				ch[1][j]=1;
			}
	}
	cout<<"频数统计如下："<<endl;
	for(i=1;ch[0][i];i++)
		cout<<ch[0][i]<<" "<<(int)ch[1][i]<<endl;
}
void main(void){
	char string[100];
	cout << "请输入一个长度不大于100的字符串："<<endl;
	cin >> string;
	string_frequency(string);
} 
