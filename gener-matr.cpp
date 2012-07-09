#include<iostream>
using namespace std;
template <typename T>
class matrix
{
	public:
		matrix(int x,int y)
		{
			T **mat=new T*[x];
			x=x;
			y=y;
			for(int i=0;i<x;i++)
			{
				mat[i] = new T[y];
				for(int j=0;j<y;j++)
					mat[i][j]=0;
			}
		}
		friend std::istream& operator>>(std::istream& is, const matrix<T>& m);
	private:
		T **mat;
		int x,y;
};
std::istream& operator>>(std::istream& is, const matrix<T>& m)
{
	for(int i=0;i<m.x;i++)
		for(int j=0;j<m.y;j++)
			is>>m.mat[i][j];
	return is;
}
int main()
{
	matrix<int> m(2,3);
	cin>>m;
}
