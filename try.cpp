// SampleCpp.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename _T, template <typename _Ty, class _Ax = allocator<_Ty> > class container>
class Stack
{
    public:
        Stack() { }
        void push(const _T& elem)
        {
            v1.push_back(elem);
        }

        void pop()
        {
            v1.pop_back();
        }

        const _T& top() const
        {
            return v1[v1.size()-1];
        }

        bool empty() const
        {
            return (v1.front() == NULL);
        }

    private:
        container<_T> v1;
};

int main()
{
    Stack<int, vector> s;
    int d;
    while(cin>>d)
    {
        s.push(d);
    }
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
#ifdef WIN32
    system("PAUSE");
#endif // WIN32
    return 0;
}
