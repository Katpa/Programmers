// BinarySearch

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch(const vector<int>& stones, int mid, int k)
{
    int cnt = 0;
    for (int iter = 0; iter < stones.size(); iter++)
    {
        if (stones[iter] < mid) cnt++;
        else cnt = 0;

        if (cnt == k) return false;
    }

    return true;
}

int solution(vector<int> stones, int k)
{
    int answer = 0;
    int left = 1;
    int right = *max_element(stones.begin(), stones.end());

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (BinarySearch(stones, mid, k))
        {
            left = mid + 1;

            if (answer < mid) answer = mid;
        }
        else
            right = mid - 1;
    }

    return answer;
}