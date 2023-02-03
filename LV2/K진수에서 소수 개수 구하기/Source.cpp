#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> conv(int n, int k) {
    vector<int> ret;
    while (n) {
        ret.push_back(n % k);
        n /= k;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int isprime(long long n) {
    if (n <= 1) return 0;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0) return 0;
    return 1;
}

int solution(int n, int k) {
    vector<int> s = conv(n, k);
    long long cur = 0;
    int answer = 0;
    for (int n : s) {
        if (n == 0) {
            answer += isprime(cur);
            cur = 0;
            continue;
        }
        cur = 10 * cur + n;
    }
    answer += isprime(cur);
    return answer;
}

int main()
{
    int n = 437674;
    int k = 3;

    int answer = solution(n, k);

    return EXIT_SUCCESS;
}