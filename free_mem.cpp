#include<iostream>
using namespace std;
template<typename t>
class pointer
{
	public:
		pointer():p(NULL)
	{}
		~pointer()
		{
			delete(p);
		}
		t* operator->()
		{

		}
		t& operator*()
		{
		}
	private:
		t *p;
};
int main()
{
	pointer<int> p1;
}
