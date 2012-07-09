#include<iostream>
using namespace std;
template <typename T>
class matrix
{
	public:
		matrix(int x,int y)
		{ 
			for(int i=0;i<x;i++)
				for(int j=0;j<y;j++)
					mat[i][j]=0;
		}

	private:
		T **mat;
};
int main()
{
	matrix<int>(2,3) m;
}
