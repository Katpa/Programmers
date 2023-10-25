#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int n)
{
    if (n & 1) return 0;

    long long m[5001] = {};

    m[0] = 1;
    m[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        m[i] = m[i - 2] * 3;
        for (int j = i - 4; j >= 0; j -= 2)
        {
            m[i] += m[j] * 2;
        }
        m[i] %= MOD;
    }

    return (int)m[n];
}