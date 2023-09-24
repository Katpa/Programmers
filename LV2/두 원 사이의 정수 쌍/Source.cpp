#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long Pr1 = pow(r1, 2);
    long long Pr2 = pow(r2, 2);

    for (long iter = 1; iter <= r2; iter++)
    {
        double maximum = sqrt(Pr2 - (iter * iter));
        double minimum = sqrt(Pr1 - (iter * iter));

        answer += (long)maximum - (long)ceil(minimum) + 1;
    }

    return answer * 4;
}