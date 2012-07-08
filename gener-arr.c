#include<iostream>
#include<vector>
using namespace std;
template <class _T>
void print(_T arr)
{
	int i=0;
	while(i<=arr.size())
	{
		cout<<arr[i]<<' ';
		i++;
	}
}
int main()
{
	vector<char> arr;
	for(int i=0;i<5;i++)
		cin>>arr[i];
	print<char> (arr);
}
