#include <iostream>
using namespace std;

template <typename _T>
class Point
{
public:
    Point(const _T& x, const _T& y);
    Point operator+(const Point& p);
    template <typename T>
    friend ostream& operator<<(ostream& os, const Point<T>& p);
private:
    _T x, y;
};

template <typename _T>
Point<_T>::Point(const _T& x, const _T& y)
    : x(x), y(y)
{ }

template <typename _T>
Point<_T> Point<_T>::operator+(const Point<_T>& p)
{
    return Point(x + p.x, y + p.y);
}

template <typename _T>
ostream& operator<<(ostream& os, const Point<_T>& p)
{
    os<<"("<<p.x<<", "<<p.y<<")";
}

int main()
{
    Point<int> p1(3,4), p2(6,8);
    cout<<p1<<", "<<p2<<endl;
    cout<<p1 + p2<<endl;
    return 0;
}
