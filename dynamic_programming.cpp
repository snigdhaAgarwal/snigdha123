#include <iostream>
#include <cassert>
using namespace std;

int fibonacci(int n)
{
    if(n < 0)
        return 0;
    int* arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    int result = arr[n];
    delete[] arr;
    return result;
}

string& getPostfix(int number)
{
    static string first = "st";
    static string second = "nd";
    static string third = "rd";
    static string other = "th";

    switch(number % 10)
    {
        case 1:
            return first;
        case 2:
            return second;
        case 3:
            return third;
        default:
            return other;
    }
}

void fibonacci_test()
{
    for(int i = 0;i < 10;i++)
    {
        cout<<i<<getPostfix(i)<<" Fibonacci Number is "<<fibonacci(i)<<endl;
    }
}

int main()
{
    fibonacci_test();
}
