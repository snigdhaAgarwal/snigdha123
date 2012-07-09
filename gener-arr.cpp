#include<iostream>
#include<vector>
using namespace std;
template <class _T>
void print(_T *arr,int size)
{
	int i=0;
	while(i<size)
	{
		cout<<arr[i]<<' ';
		i++;
	}
}
int main()
{
//	vector<char> arr;
//	for(int i=0;i<5;i++)
//		cin>>arr[i];
char arr[]={'a', 'b', 'c', 'd', 'e' };	
print<char> (arr,5);
}
