#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> discount;
vector<string> want;

bool IsCorrect(int startNum, map<string, int> m);

int solution(vector<string> _want, vector<int> number, vector<string> _discount)
{
    int answer = 0;
    map<string, int> m;
    want = _want;
    discount = _discount;

    for (int i = 0; i < want.size(); i++)
        m[want[i]] = number[i];

    //함수로 관리하자

    for (int i = 0; i < discount.size() - 9; i++)
    {
        if (IsCorrect(i, m))
            answer++;
    }

    return answer;
}

bool IsCorrect(int startNum, map<string, int> m)
{
    for (int i = startNum; i < startNum + 10; i++)
    {
        for (int j = 0; j < want.size(); j++)
        {
            if (want[j] == discount[i])
            {
                if (m[want[j]] < 1)
                    return false;

                m[want[j]]--;
                break;
            }
            else if (j == want.size() - 1)
                return false;
        }
    }

    return true;
}

int main()
{
    vector<string> _want = { "banana", "apple", "rice", "pork", "pot" };
    vector<int> number = { 3, 2, 2, 2, 1 };
    vector<string> _discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    int answer = solution(_want, number, _discount);

    return EXIT_SUCCESS;
}