#include <iostream>
using namespace std;

int main()
{
    int k = 20;
    (++(++k));

    cout<<k;

    ((k++)++);

    cout<<k;

    return 0;
}
