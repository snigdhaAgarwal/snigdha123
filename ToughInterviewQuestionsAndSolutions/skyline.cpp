#include <iostream>
#include <iomanip>

using namespace std;

// Problem Statement http://acm.uva.es/p/v1/105.html
//
// Solution Complexity: O(Mn) where M is the maximum width n is the number of points

int main()
{
    int height[10001] = {0};

    int left, buildingHeight, right, maxright = 0, maxheight = 0;

    // Scan till EOF
    while(cin>>left>>buildingHeight>>right)
    {
        for(int i = left;i < right;i++)
        {
            if(buildingHeight > height[i])
                height[i] = buildingHeight;
        }
        if(maxright < right)
            maxright = right;
        if(maxheight < buildingHeight)
            maxheight = buildingHeight;
    }

    // Formatting as per answer required
    bool first = true;

    int currentHeight = 0;
    for(int pos = 0;pos <= maxright;pos++)
    {
        if(height[pos] != currentHeight)
        {
            if(!first)
            {
                cout<<' ';
            }
            else
            {
                first = false;
            }
            cout<< pos << ' ' << height[pos];
            currentHeight = height[pos];
        }
    }

    cout<<endl;
    
    // Just for formatting and printing a good view
    for(int i = maxheight;i >= 0;i--)
    {
        for(int j = 0;j <= maxright;j++)
        {
            cout<<(height[j] >= i ? " * " : "   ");
        }
        cout<<endl;
    }

    for(int j = 0;j <= maxright;j++)
    {
        cout<<setw(2)<<height[j]<<" ";
    }
    cout<<endl;

    return 0;
}
