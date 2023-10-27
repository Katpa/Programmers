#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long DP(vector<int> arr)
{
    vector<long long> vec(arr.size());

    vec[0] = arr[0];

    for (int i = 1; i < arr.size(); i++)
        vec[i] = max((long long)0, vec[i - 1]) + arr[i];

    return *max_element(vec.begin(), vec.end());
}

long long solution(vector<int> sequence)
{
    long long answer = 0;
    vector<int> s1 = sequence, s2 = sequence;

    for (int i = 0; i < sequence.size(); i++)
    {
        if (i & 1)
            s1[i] *= -1;
        else
            s2[i] *= -1;
    }

    answer = max(DP(s1), DP(s2));

    return answer;
}