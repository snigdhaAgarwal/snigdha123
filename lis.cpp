//longest increasing sequence
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> seq;
	int size;
	cin>>size;
	for(int i=0;i<size;i++)
		cin>>seq[i];
	vector<int> l;
	l[0]=1;
	for(int i=1;i<size;i++)
	{
		if(seq[i]>seq[i-1])
			l[i]=l[i-1]+1;
		else if(seq[i]<seq[i-1])
		{
			int j=i-1;
			while(seq[j]>seq[i])
				j--;
			l[i]=l[j]+1;
		}
	}
	int max;
	for(int i=1;i<size;i++)
	{
		max=l[0];
		if(max<l[i])
			max=l[i];
	}
	cout<<max<<endl;
	return 0;
}
