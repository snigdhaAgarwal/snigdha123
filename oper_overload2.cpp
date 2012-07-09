/*2 things to b done..
 * 1.input a point using cin>>p
 * 2.compare two points ie p1==p2  */
#include<iostream>
using namespace std;
class point
{
    public:
        point(int x1,int y1):x(x1),y(y1){}
        int x,y;
        
        bool operator==(const point &p1) const
        {
            if(p1.x==x && p1.y==y)
                return 1;
            return 0;
        }
};

std::istream& operator>>(std::istream& is,point& p)
{
    // p.x and p.y are public. Hence no need to be friend
    is>>p.x>>p.y;
    return is;
}

std::ostream& operator<<(std::ostream os, const point& p)
{
    // p.x and p.y are public. Hence no need to be friend
    os<<"("<<p.x<<", "<<p.y<<")";
    return os;
}

int main()
{
    point p1(1,2),p2(7,3);
    cin>>p1;
    cin>>p2;
    cout<<(p1 == p2) ? "same" : "not";
    cout<<endl;
}
