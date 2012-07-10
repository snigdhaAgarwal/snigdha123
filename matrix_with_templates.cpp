#include <iostream>
#include <stdexcept>

using namespace std;

template <unsigned int R, unsigned int C, typename _T = int>
class matrix
{
public:
	matrix()
	{
		mat = new _T*[R];
		for(unsigned int i = 0;i < R;i++)
		{
			mat[i] = new _T[C];
		}
	}

	_T* operator[](int index)
	{
		if(index >= R)
		{
			throw std::out_of_range("Index out of range");
		}
		return mat[index];
	}

	const _T* operator[](int index) const
	{
		if(index >= R)
		{
			throw std::out_of_range("Index out of range");
		}
		return mat[index];
	}

private:
	_T** mat;
};

template <unsigned int R, unsigned int C, typename _T>
matrix<R, C, _T> operator+(const matrix<R, C, _T>& m1, const matrix<R, C, _T>& m2)
{
	matrix<R, C, _T> answer;
	for(unsigned int i = 0;i < R;i++)
	{
		for(unsigned int j = 0;j < C;j++)
		{
			answer[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return answer;
}

template <unsigned int R, unsigned int C, typename _T>
std::ostream& operator<<(std::ostream& os, const matrix<R, C, _T>& m)
{
	for(unsigned int i = 0;i < R;i++)
	{
		for(unsigned int j = 0;j < C;j++)
		{
			os<<m[i][j]<<" ";
		}
		os<<std::endl;
	}
	return os;
}

template <unsigned int R, unsigned int C, typename _T>
std::istream& operator>>(std::istream& is, matrix<R, C, _T>& m)
{
	for(unsigned int i = 0;i < R;i++)
	{
		for(unsigned int j = 0;j < C;j++)
		{
			is>>m[i][j];
		}
	}
	return is;
}

int main()
{
	matrix<3,3> m1;
	cin>>m1;

	matrix<3,3> m2;
	cin>>m2;

	cout<<m1 + m2; // perfectly valid as both are matrix<3,3>

	matrix<4,4> m3;
	cin>>m3;

	// cout<<m1 + m3; // error because m1 is of type matrix<3,3> where as m3 is of typye matrix<4,4>
#ifdef WIN32
	system("PAUSE");
#endif // WIN32

	return 0;
}
