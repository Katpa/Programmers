#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0, queue_size = queue1.size(), queIndex1 = 0, queIndex2 = 0;
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    while (answer <= (queue_size << 2))
    {
        if (sum1 < sum2)
        {
            sum1 += queue2[queIndex2];
            sum2 -= queue2[queIndex2];
            queue1.push_back(queue2[queIndex2++]);
        }
        else if (sum2 < sum1)
        {
            sum2 += queue1[queIndex1];
            sum1 -= queue1[queIndex1];
            queue2.push_back(queue1[queIndex1++]);
        }
        else
        {
            return answer;
        }
        ++answer;
    }
    return -1;
}

int main()
{
    vector<int> queue1 = { 3, 2, 7, 2 };
    vector<int> queue2 = { 4, 6, 5, 1 };

    int answer = solution(queue1, queue2);

    return EXIT_SUCCESS;
}