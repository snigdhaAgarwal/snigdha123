#include<iostream>
using namespace std;
template<typename t>
class pointer
{
	public:
		pointer(t *p1) : p(p1) {}
		~pointer()
		{
			delete p;
		}
		t* operator->()
		{
			return p;
		}
		const pointer& operator=(t *p1)
		{
			p=p1.p;
			return (* this);
		}
		t& operator*()
		{
			return (*p);
		}
	private:
		t *p;
};
int main()
{
	pointer<int> p=new int;
}
