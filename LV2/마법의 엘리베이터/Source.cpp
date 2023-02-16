#include <string>
#include <vector>

using namespace std;

//---------------------------------------------------------
// �� ������ �ٽ��� 5�̴�.
// ���ڸ� ������ �ִ��ڸ� ������ ���ʴ�� �˻��ϴ� ���� �⺻ �����̴�.
// �⺻������ �˻��ϴ� �ڸ��� 5���Ͽ� 6�̻����� ������.
// ������ 5�� �ѹ� �� �˻縦 �ؾ��Ѵ�.
//---------------------------------------------------------
// 6 �̻� - �� ��쿣 �ø� �� ������ ���ִ°� ����
// 5�̰� �����ڸ��� 5 - ������
// �׿� - ������
//---------------------------------------------------------
// ��ǥ���� TC: 555
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