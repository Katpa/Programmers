#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define LONGLONG_MAX 9223372036854775807

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long num : numbers)
    {
        for (long long i = 1; i < LONGLONG_MAX; i = i << 1)
        {
            if ((num & i)) continue;
            answer.push_back(num - (i >> 1) + i);
            break;
        }
    }
    return answer;
}

int main()
{
    vector<long long> numbers = { 2, 7 };

    vector<long long> answer = solution(numbers);

    return EXIT_SUCCESS;
}