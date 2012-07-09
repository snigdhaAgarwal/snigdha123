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

template <>
void print<char>(char *arr,int size)
{
	int i=0;
	while(i < size && arr[i] != '\0')
	{
		cout<<arr[i];
		i++;
	}
}

template <int n>
struct factorial
{
	enum { value = n * factorial<n-1>::value };
};

template <>
struct factorial<0>
{
	enum { value = 1 };
};

int main()
{
//	vector<char> arr;
//	for(int i=0;i<5;i++)
//		cin>>arr[i];
	char arr[]={'a', 'b', 'c', 'd', 'e' };	
	print(arr,5);
	int arr1[] = { 1, 2, 3, 4, 5 };
	print(arr1,5);
	cout<<endl;
	cout<<factorial<10>::value<<endl;
}
