// SampleCpp.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

template <typename _T>
class Stack
{
public:
    Stack() : start(NULL) { }
	~Stack()
	{
		Node* temp = start;
		while(start != NULL)
		{
			start = start->m_next;
			delete temp;
			temp = start;
		}
	}

	void push(const _T& elem)
	{
		Node* n = new Node(elem, start);
		start = n;
	}

	void pop()
	{
		Node* t = start;
		start = start->m_next;
		delete t;
	}

	const _T& top() const
	{
		return start->m_data;
	}

	bool empty() const
	{
		return (start == NULL);
	}

private:
	struct Node
	{
		_T    m_data;
		Node* m_next;
		Node(const _T& data, Node* next)
			: m_data(data), m_next(next) { }
	};

	Node* start;
};

int main()
{
	Stack<int> s;
	int d;
	while(cin>>d)
	{
		s.push(d);
	}

	while(!s.empty())
	{
		cout<<s.top()<<endl;
		s.pop();
	}

#ifdef WIN32
	system("PAUSE");
#endif // WIN32
	return 0;
}