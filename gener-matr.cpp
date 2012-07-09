#include<iostream>
using namespace std;
template <typename T>
class matrix
{
	public:
		matrix(int x,int y):x(x),y(y)
		{
			mat=new T*[x];
			for(int i=0;i<x;i++)
			{
				mat[i] = new T[y];
				for(int j=0;j<y;j++)
					mat[i][j]=0;
			}
		}
		matrix<T> operator+(const matrix<T>& m) const
		{
			matrix<T> m2(m.x,m.y);
			for(int i=0;i<m.x;i++)
				for(int j=0;j<m.y;j++)
				{
					m2.mat[i][j]=m.mat[i][j]+mat[i][j];
				}
			return m2;
		}
		template<typename T1>
			friend std::istream& operator>>(std::istream& is, const matrix<T1>& m);
	private:
		T **mat;
		int x,y;
};


template <typename T>
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
	matrix<int> m1(2,3);
	matrix<int> m2(2,3);
	cin>>m;
	cin>>m1;
	m2=m+m1;
}
