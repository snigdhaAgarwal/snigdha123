#include<iostream>
using namespace std;
void func(const string& x,const string &y)
{
    int l1=x.length();
    int l2=y.length();
    string st[l1];
    int a=0;
    int p;
    for(int i=0;i<l1;i++)
    {
        int oldi=i;
        for(int j=0;j<l2;j++)
        {
            if(x[i]==y[j])
            {
                st[a]+=y[j];
                i++;
                p=j;
            }
            else if(x[i]!=y[j] && j==l2-1)
            {
                i++;
                j=p;
            }
        }
        a++;
        i=oldi;
    }
    int max=0,maxi=0;
    for(int i=0;i<a;i++)
    {
       /* int j=0;
        while(st[i][j]!='#')
        {
            j++;
        }*/
        int j=st[i].length();
        if(max<j)
        {
            max=j;
            maxi=i;
        }
    }
    cout<<"max subsequence is "<<max<<" and the subsequence is "<<st[maxi]; 
}
int main()
{
    string st1,st2;
    cin>>st1;
    cin>>st2;
    func(st1,st2);
}
