#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> ableNums;
vector<bool> prime;

int GetPrimeAmount();
void SetPrime();
void SetNum(string s, int n, vector<char> chars);

int solution(string numbers) {
    int answer;
    vector<char> chars;

    sort(numbers.begin(), numbers.end());

    for (char ch : numbers)
        chars.push_back(ch);

    //재귀함수를 이용한 수 조합
    for (int i = 0; i < numbers.length(); i++)
    {
        SetNum("", i, chars);
    }

    sort(ableNums.begin(), ableNums.end());

    answer = GetPrimeAmount();
    return answer;
}

void SetNum(string s, int n, vector<char> chars)
{
    s += chars[n];
    ableNums.push_back(stoi(s));
    chars.erase(chars.begin() + n);

    for (int i = 0; i < chars.size(); i++)
        SetNum(s, i, chars);
}

int GetPrimeAmount()
{
    int primeNum = 0;
    int lastNum = 0;

    SetPrime();

    for (int num : ableNums)
    {
        if (lastNum < num && prime[num])
            primeNum++;

        lastNum = num;
    }

    return primeNum;
}

void SetPrime()
{
    int max = *max_element(ableNums.begin(), ableNums.end());

    prime.resize(max + 1);
    prime.assign(max + 1, true);

    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i * i < max; i++)
    {
        if (prime[i])
            for (int j = i * i; j <= max; j += i)
                prime[j] = false;
    }
}

int main()
{
    string numbers = "17";

    int answer = solution(numbers);

    return EXIT_SUCCESS;
}