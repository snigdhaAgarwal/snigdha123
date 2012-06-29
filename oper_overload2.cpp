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
        std::istream& operator>>(std::istream& is,point& p)
        {
            is>>p.x>>p.y;
       //     is>>p.y;
            return is;
        }
        int operator==(const point &p1)
        {
            if(p1.x==x && p1.y==y)
                return 1;
            return 0;
        }
     /*   std::ostream& operator<<(std::ostream& os,point &p)
        {
            return os
        }*/
};

int main()
{
    point p1(1,2),p2(7,3);
    cin>>p1;
    cin>>p2;
    cout<<(p1 == p2) ? "same" : "not";
    cout<<endl;
}
