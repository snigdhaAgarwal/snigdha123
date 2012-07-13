#include<iostream>
using namespace std;
int p=0;
int binsearch(int high,int low,int *a,int x)
{
    int mid=(high+low)/2;
    if(low>high)
    {
        // ideally while creating functions, it isn't good to write print statements.
        // if you want you can write after the function returns from where it is called.
        // this is because, the caller cannot get the printed value.
        //
        // There is something called logging where we print just for debugging purposes
        // but logging is disabled on final output. Will cover logging this weekend.
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
    T* mid = begin+(end - begin) / 2; // pointer division is not support by all compilers. to be safe did this
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
void mergesort(int *a,int *end,int size)
{
    if(size==0||size==1)
        return;
    else
    {
        mergesort(a,a+(end-a)/2,1+(end-a)/2);
        mergesort(a+1+(end-a)/2,end,end-(a+1+(end-a)/2)+1);
        int i=0;
        int index=0;
        int arr[size];
        int j=1+(end-a)/2;
        while(a+i<=a+(end-a)/2 && a+j<=end)
        {
            if(a[i]<a[j])
                arr[index++]=a[i++];
            else 
                arr[index++]=a[j++];
        }
        while(a+i <= a+(end-a)/2)
            arr[index++]=a[i++];
        while(a+j<=end)
            arr[index++]=a[j++];
        for(int i=0;a+i<=end;i++)
            a[i]=arr[i];
    }
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
    int a[] = {4,6,1,72,8,3,11,9};
    mergesort(a,a+7,8);
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
