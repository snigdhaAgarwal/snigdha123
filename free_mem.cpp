#include<iostream>
using namespace std;
template<typename t>
class pointer
{
	public:
		pointer() : p(NULL) {}
		~pointer()
		{
			delete p;
		}
		t* operator->()
		{
            return p;
		}
const pointer& operator=(const pointer& p1)
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
	pointer<int> p1;
}
