#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string a, string b)
{
    if (a + b > b + a)
        return true;
    else
        return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strArr;

    for (int num : numbers)
        strArr.push_back(to_string(num));

    sort(strArr.begin(), strArr.end(), Compare);

    for (string str : strArr)
        answer += str;

    if (answer[0] == '0')
        return "0";

    return answer;
}

int main()
{
    vector<int> numbers = { 6, 10, 2 };

    string answer = solution(numbers);

    return EXIT_SUCCESS;
}