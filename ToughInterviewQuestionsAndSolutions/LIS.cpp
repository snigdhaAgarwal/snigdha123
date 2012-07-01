#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

#define SIZEOF_ARRAY(x) (sizeof(x) / sizeof(x[0]))

template <typename T>
class StrictlyWeakOrdering
{
public:
    StrictlyWeakOrdering(const vector<T>& arr)
        : m_arr(arr) { }
    bool operator()(const int& i, const int& j)
    {
        return m_arr[i] < m_arr[j];
    }
private:
    const vector<T>& m_arr;
};

template <typename T>
vector<T> LIS(const vector<T>& seq)
{
    vector<int> p(seq.size());
    int u, v;

    if(seq.empty())
        return vector<T>();

    vector<int> lis_indices;
    lis_indices.push_back(0);

    StrictlyWeakOrdering<T> l(seq);

    for(size_t i = 1;i < seq.size();i++)
    {
        // If seq[i] is greater or equal to than current longest subsequence seq[lis_indices.back()]
        // just add it to the LIS Sequence
        if(seq[i] >= seq[lis_indices.back()])
        {
            p[i] = lis_indices.back();
            lis_indices.push_back(i);
        }
        else
        {
            // find k such that k is in the LIS and k is just > than seq[i]. upper_bound does just that
            size_t k = upper_bound(lis_indices.begin(), lis_indices.end(), i, l) - lis_indices.begin();

            if(seq[lis_indices[k]] >= seq[i])
            {
                if(k > 0)
                    p[i] = lis_indices[k - 1];
                lis_indices[k] = i;
            }
        }
    }

    vector<T> answer(lis_indices.size());
    int i = lis_indices.size() - 1;
    int val = lis_indices[i];
    while(i >= 0)
    {
        answer[i] = seq[val];
        val = p[val];
        --i;
    }

    return answer;
}

int main()
{
    int arr[] = { 1, 9, 3, 8, 11, 3, 4, 5, 6, 4, 19, 7, 1, 7 };
    
    vector<int> seq(arr, arr + SIZEOF_ARRAY(arr));
    vector<int> lis = LIS(seq);

    // Print the output
    copy(lis.begin(), lis.end(), ostream_iterator<int>(cout, " "));
    cout<<endl;
}
