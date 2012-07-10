#include<iostream>
using namespace std;
template<typename t=int>
class fact1
{
	public:
		fact1(int x):x(x)
	{}
		int fact()
		{
			t prod=1;
			while(x>0)
			{
				prod=prod*x;
				x--;
		//		cout<<prod<<endl;
			}			
			return prod;
		}
	private:
                t x;
};
int main()
{
	fact1<int> f(3);
	int k=f.fact();
	cout<<k<<endl;
}
