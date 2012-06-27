#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int v = 0) : _val(v) { }
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

    ((k++)++);

    cout<<k<<endl;

    return 0;
}
