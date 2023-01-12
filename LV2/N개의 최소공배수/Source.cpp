#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;

    sort(arr.rbegin(), arr.rend());

    int factor = 1;

    while (true)
    {
        int tmpNum = arr[0] * factor;
        int count = 0;

        for (int num : arr)
        {
            if ((tmpNum % num) != 0)
                break;

            count++;
        }

        if (count == arr.size())
        {
            answer = tmpNum;
            break;
        }

        factor++;
    }

    return answer;
}

int main()
{
    vector<int> arr = { 2, 6, 8, 14 };
    int answer = solution(arr);
    
    return EXIT_SUCCESS;
}