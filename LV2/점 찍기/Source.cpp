#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long GetVertexCountOnX(int x, int d, int k)
{
    long long output = 0;
    long long dd = (long long)d * (long long)d;
    long long xx = (long long)x * (long long)x;

    output = (long long)sqrt(dd - xx);
    output /= k;
    output++;

    return output;
}

long long solution(int k, int d) {
    long long answer = 0;

    for (int i = 0; i <= d; i += k)
        answer += GetVertexCountOnX(i, d, k);

    return answer;
}

int main()
{
    int k = 2;
    int d = 4;

    long long answer = solution(k, d);

    return EXIT_SUCCESS;
}