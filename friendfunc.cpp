#include <iostream>
using namespace std;

class Point
{
public:
    Point(int x, int y) : x(x), y(y) { }
    friend void print(const Point& p);
private:
    int x, y;
};

// print is not a part of Point. Hence it'll take an argument
// and won't be Point::print
void print(const Point& p)
{
    cout<<p.x<<", "<<p.y<<endl;
}

int main()
{
    Point p1(2,3), p2(3,4);
    print(p1);
    print(p2);
    return 0;
}
