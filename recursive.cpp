#include<iostream>
using namespace std;
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
}
