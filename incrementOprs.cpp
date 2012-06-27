#include <iostream>
#include <execinfo.h>
using namespace std;

class Integer
{
public:
    Integer(int v = 0) : _val(v) { }
    Integer(const Integer& v) : _val(v._val) 
    { 
        cout<<"Copy Constructor Called with value "<<_val<<endl;
        cout<<"Stack Trace"<<endl;

        void* btarray[10];
        size_t size = backtrace(btarray, 10);
        backtrace_symbols_fd(array, size, 2);
    }
    Integer& operator++()
    {
        ++_val;
        return *this;
    }

    Integer operator++(int)
    {
        Integer ans = (*this);
        ++(*this);
        return ans;
    }
    friend ostream& operator<<(ostream& os, const Integer& i);
private:
    int _val;
};

ostream& operator<<(ostream& os, const Integer& i)
{
    os<<i._val;
}

int main()
{
    Integer k = 20;
    (++(++k));

    cout<<k<<endl;

    k = 30;

    ((k++)++);

    cout<<k<<endl;

    return 0;
}
