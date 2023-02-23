#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int Func(int num)
{
    if (num == 1) return 0;

    if (num & 1 || num > 20000000)
    {
        if (isPrime(num)) return 1;
        else
        {
            vector<int> vec;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i != 0) continue;

                // ������ ���� �� �ϳ��̴�.
                // ������ ������ �ָ��ϱ� ������
                // ����� �� ������ 10���������
                // ����� 1õ���� �ѱ� �� ����
                vec.push_back(i > 10000000 ? 0 : i);
                vec.push_back(num / i > 10000000 ? 0 : num / i);
            }

            return *max_element(vec.begin(), vec.end());
        }
    }
    else
    {
        return (num >> 1);
    }
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

    for (int i = begin; i <= end; i++)
    {
        answer.push_back(Func(i));
    }

    return answer;
}

int main()
{
    //������ ����� ���� �ʰ��� ��츦 ���� TC
    long long begin = 100000014;
    long long end = 100000016;

    vector<int> answer = solution(begin, end);

    return EXIT_SUCCESS;
}