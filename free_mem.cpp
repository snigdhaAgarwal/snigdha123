#include<iostream>
using namespace std;
template<typename t>
class pointer
{
	public:
		pointer(t *p1) : p(p1) {}
        pointer(pointer& p) : p(p.release()) { }
		~pointer()
		{
			delete p;
		}
		t* operator->()
		{
			return p;
		}
		pointer& operator=(t *p1)
		{
			p=p1.p;
			return (*this);
		}
        pointer& operator=(pointer& p1)
        {
            p=p1.release();
        }
        t *release()
        {
            t *temp=p;
            p=NULL;
            return temp;
        }
		t& operator*()
		{
			return (*p);
		}

        template <typename T>
        friend ostream& operator<<(ostream& os, const pointer<T>& p);
	private:
		t *p;
};

template <typename T>
ostream& operator<<(ostream& os, const pointer<T>& p)
{
    os<<p.p;
    return os;
}

int main()
{
	pointer<int> p=new int;
    (*p) = 30;
    pointer<int> p1 = p;
    cout<<(*p1)<<endl;
    cout<<p<<endl;
    return 0;
}
