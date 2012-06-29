#include <iostream>
#include <cassert>
#include <algorithm>
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

int LongestCommonSubsequence(const string& X, const string& Y)
{
    int l1 = X.length();
    int l2 = Y.length();

    if(l1 == 0 || l2 == 0)
    {
        return 0;
    }

    if(X[l1 - 1] == Y[l2 - 1]) // last character same
    {
        return 1 + LongestCommonSubsequence(X.substr(0, l1 - 1), Y.substr(0, l2 - 1));
    }
    else
    {
        return max(LongestCommonSubsequence(X.substr(0, l1 - 1), Y), LongestCommonSubsequence(X, Y.substr(0, l2 - 1)));
    }
}

void LCS_test()
{
    cout<<"LCS of "<<"carbon"<<" and "<<"argon"<<" is "<<LongestCommonSubsequence("carbon", "argon")<<endl;
    cout<<"LCS of "<<"carbon"<<" and "<<"argonc"<<" is "<<LongestCommonSubsequence("carbon", "argonc")<<endl;
}

int main()
{
    cout<<"Fibonacci"<<endl;
    fibonacci_test();

    cout<<"LCS"<<endl;
    LCS_test();

    return 0;
}
