#include<iostream>
using namespace std;
int p=0;
int binsearch(int high,int low,int *a,int x)
{
    int mid=(high+low)/2;
    if(low>high)
    {
        cout<<"not found"<<endl;
        return -1;
    }
    else if(a[mid]>x)
        p=binsearch(mid-1,low,a,x);
    else if(a[mid]<x)
        p=binsearch(high,mid+1,a,x);
    else if(a[mid]==x)
        return mid+1;
    return p;
}

// Binary Search With Templates and pointers
template <typename T>
T* binsearch(T* begin, T* end, int x)
{
    T* mid = begin + (end - begin) / 2; // pointer division is not support by all compilers. to be safe did this
    if(begin >= end)
        return NULL;
    else if(*mid > x)
        return binsearch(begin, mid, x);
    else if(*mid < x)
        return binsearch(mid + 1, end, x);
    else
        return mid;
}

int gcd(int a,int b)
{
    if(a%b==0 || b == 0) // in case b == 0, we may run into divison by 0
        return b;
    else
        return gcd(b,a%b);
}

int ncr(int n,int r)
{
    if(r>n)
        return 0;
    else if(n==0||r==0)
        return 1;
    return (ncr(n-1,r)+ncr(n-1,r-1));
}
int main()
{
    int x=ncr(5,3);
    cout<<x<<endl;
    int m=gcd(58,26);
    cout<<m<<endl;
    int temp;
    int a[] = {4,6,1,72,8,3,11,9};
    for(int i=0;i<7;i++)
        for(int j=i+1;j<8;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    for(int i=0;i<8;i++)
        cout<<a[i]<<' ';
    cout<<endl;
    cout<<"enter value:";
    int val;
    cin>>val;
    int pos=binsearch(7,0,a,val);
    if(pos!=-1)
        cout<<"value is at pos :"<<pos<<endl;
    int* elem=binsearch(a, a + 8, 100);
    cout<<elem<<" "<<(elem != NULL ? *elem : -1)<<endl;
    elem=binsearch(a, a + 8, 72);
    cout<<elem<<" "<<(elem != NULL ? *elem : -1)<<endl;
    elem=binsearch(a, a + 8, 1);
    cout<<elem<<" "<<(elem != NULL ? *elem : -1)<<endl;
    elem=binsearch(a, a + 8, -10);
    cout<<elem<<" "<<(elem != NULL ? *elem : -1)<<endl;
}
