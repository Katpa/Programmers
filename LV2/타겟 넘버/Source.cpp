#include <string>
#include <vector>

using namespace std;

int answer = 0;

void targetNumber(vector<int> numbers, int target, int sum, int count)
{
    if (count == numbers.size())
    {
        if (sum == target) answer++;

        return;
    }
    targetNumber(numbers, target, sum + numbers[count], count + 1);
    targetNumber(numbers, target, sum - numbers[count], count + 1);
}
int solution(vector<int> numbers, int target)
{
    targetNumber(numbers, target, 0, 0);
    return answer;
}

int main()
{
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int target = 3;

    int answer = solution(numbers, target);

    return EXIT_SUCCESS;
}