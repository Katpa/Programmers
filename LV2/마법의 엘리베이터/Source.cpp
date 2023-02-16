#include <string>
#include <vector>

using namespace std;

//---------------------------------------------------------
// 이 문제의 핵심은 5이다.
// 일자리 수부터 최대자리 수까지 차례대로 검사하는 것이 기본 과정이다.
// 기본적으로 검사하는 자리가 5이하와 6이상으로 나뉜다.
// 하지만 5는 한번 더 검사를 해야한다.
//---------------------------------------------------------
// 6 이상 - 이 경우엔 올린 후 역으로 빼주는게 좋다
// 5이고 다음자리도 5 - 역뺄셈
// 그외 - 정뺄셈
//---------------------------------------------------------
// 대표적인 TC: 555
//---------------------------------------------------------

int solution(int storey) {
    int answer = 0;

    while (storey > 0)
    {
        int tmp = storey % 10;
        int m = 10 - tmp;

        if (tmp > 5)
        {
            storey += m;
            answer += m;
        }
        else if (tmp == 5 && (storey / 10) % 10 >= 5)
        {
            storey += m;
            answer += m;
        }
        else
        {
            answer += tmp;
        }
        storey /= 10;
    }

    return answer;
}

int main()
{
    int storey = 555;

    int answer = solution(storey);

    return EXIT_SUCCESS;
}