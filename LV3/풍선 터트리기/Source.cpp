#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a)
{
    int answer = 0;
    int size = a.size();

    int* leftMin = new int[size];
    int* rightMin = new int[size];
    leftMin[0] = a[0];
    rightMin[size - 1] = a.back();

    int index = 1;
    for (; index < size; index++)
    {
        leftMin[index] = leftMin[index - 1] < a[index] ? leftMin[index - 1] : a[index];
    }

    index -= 2;
    for (; index >= 0; index--)
    {
        rightMin[index] = rightMin[index + 1] < a[index] ? rightMin[index + 1] : a[index];
    }

    for (index = 0; index < size; index++)
    {
        if (leftMin[index] >= a[index] || rightMin[index] >= a[index])
            answer++;
    }

    return answer;
}