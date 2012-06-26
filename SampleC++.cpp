#include <iostream>

class point2D
{
public:
	point2D(int x, int y) : m_nX(x), m_nY(y) { }
	point2D() : m_nX(0), m_nY(0) { }

	// Define Addition of two points
	point2D operator+(const point2D& p) const
	{
		return point2D(m_nX + p.m_nX, m_nY + p.m_nY);
	}

	// Definie Assignment of one point to another
	// Not needed in this case, but just for demo purpose
	const point2D& operator=(const point2D& p)
	{
		m_nX = p.m_nX;
		m_nY = p.m_nY;
		return (*this); // Guess why this return statement?
	}

	// Give access to p.x as p[0] and p.y as p[1]
	int& operator[](int index)
	{
		switch(index)
		{
		case 0:
			return m_nX;
		case 1:
			return m_nY;
		}
	}

	const int& operator[](int index) const
	{
		switch(index)
		{
		case 0:
			return m_nX;
		case 1:
			return m_nY;
		}
	}

	// defining a function as friend, not a class function
	// another way of defining a operator
	friend point2D operator+(const int& x, const point2D& p);

	// defining << to use used as cout<<p
	// cout is a variable of type std::ostream
	// cin is a variable of type std::istream
	// we return reference to ostream and not a const reference
	// as it can be modified
	friend std::ostream& operator<<(std::ostream& os, const point2D& p);

private:
	int m_nX;
	int m_nY;
};

point2D operator+(const int& x, const point2D& p)
{
	return point2D(p.m_nX + x, p.m_nY);
}

std::ostream& operator<<(std::ostream& os, const point2D& p)
{
	os<<"("<<p.m_nX<<", "<<p.m_nY<<")";
	return os;
}

using std::cout;
using std::cin;
using std::endl;

int main()
{
	point2D p1(3,4), p2(6,8);
	cout<<"P1 = "<<p1<<endl;
	cout<<"P2 = "<<p2<<endl;
	cout<<"P1 + P2 = "<<p1 + p2<<endl;
	cout<<"5 + P1 = "<<5 + p1<<endl;

	point2D p3;
	cin>>p3[0];
	cin>>p3[1];
	cout<<p3<<endl;

#ifdef WIN32
	// Stop on windows. Ignore on linux.
	system("PAUSE");
#endif

	return 0;
}