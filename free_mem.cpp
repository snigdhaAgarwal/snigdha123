#include<iostream>
using namespace std;
template<typename t>
class pointer
{
pointer():p(NULL)
{}
private:
t *p;
};
int main()
{
pointer<int> p1;
}
