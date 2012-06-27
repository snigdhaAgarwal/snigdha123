#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int v = 0) : _val(v) { }
<<<<<<< HEAD
    Integer(const Integer& v) : _val(v._val) 
    { 
        cout<<"Copy Constructor Called with value "<<_val<<endl;
        cout<<"Stack Trace"<<endl;

        void* btarray[10];
        size_t size = backtrace(btarray, 10);
        backtrace_symbols_fd(btarray, size, 2);
    }
=======
    Integer(const Integer& v) : _val(v._val) { }
>>>>>>> 8285ced6338f642c1939d4b8f4519a513bed9e2c
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

    operator int()
    {
        return _val;
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

    Integer k1 = 30;

    cout<<k + k1<<endl;

    return 0;
}
