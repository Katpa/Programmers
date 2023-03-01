#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<float, long long> m;

    for (long long weight : weights)
        m[weight]++;

    map<float, long long>::iterator iter1;
    map<float, long long>::iterator iter2;

    for (iter1 = m.begin(); iter1 != m.end(); iter1++)
    {
        if ((*iter1).second > 1)
        {
            long long sum = 0;
            for (long long i = (*iter1).second - 1; i > 0; i--)
                sum += i;

            answer += sum;
        }
        iter2 = iter1;
        iter2++;
        for (; iter2 != m.end(); iter2++)
        {
            float rate = min((*iter1).first, (*iter2).first) / max((*iter1).first, (*iter2).first);

            if (rate == 0.75f)
                answer += (*iter1).second * (*iter2).second;
            else if (rate == 0.5f)
                answer += (*iter1).second * (*iter2).second;
            else if (rate == 2.0f / 3.0f)
                answer += (*iter1).second * (*iter2).second;
        }
    }

    return answer;
}

int main()
{
    vector<int> weights = { 100,180,360,100,270 };

    long long answer = solution(weights);

    return EXIT_SUCCESS;
}