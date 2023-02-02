#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    vector<int> nums;
    int num = n;

    while (true)
    {
        int r = num % 3;
        int d = num / 3;

        nums.push_back(r);

        if (!r) d--;

        if (d == 0) break;

        num = d;
    }

    for (int i = nums.size() - 1; i > -1; i--)
    {
        switch (nums[i])
        {
        case 1:
            answer += '1';
            break;
        case 2:
            answer += '2';
            break;
        case 0:
            answer += '4';
            break;
        }
    }

    return answer;
}

int main()
{
    int n = 1;

    string answer = solution(n);

    return EXIT_SUCCESS;
}