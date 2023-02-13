#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int idx = 0;
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());

    for (int num : A)
    {
        for (; idx < B.size(); idx++)
        {
            if (num < B[idx])
            {
                answer++;
                idx++;
                break;
            }
        }
    }


    return answer;
}

int main()
{
    vector<int> A = { 5, 1, 3, 7 };
    vector<int> B = { 2, 2, 6, 8 };

    int answer = solution(A, B);

    return EXIT_SUCCESS;
}