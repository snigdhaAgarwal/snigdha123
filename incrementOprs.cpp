#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int v = 0) : _val(v) { }
    Integer(const Integer& v) : _val(v._val) { }
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
