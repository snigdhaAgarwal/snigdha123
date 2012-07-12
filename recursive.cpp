#include<iostream>
using namespace std;
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
    int p=gcd(58,26);
    cout<<p<<endl;
}
