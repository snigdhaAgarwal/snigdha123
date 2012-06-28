#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;
int main()
{
    vector<int> v(10);
    try
    {
        cout<<v.at(116);
    }
    catch (out_of_range& e)
    {
        cerr<<"Out of range error: "<<e.what()<<endl;
    }
}
