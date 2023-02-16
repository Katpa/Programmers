using namespace std;

//----------------------------------------------------------
// �β������� �մ� �밢���� ��ġ�� ������ ����
//      = ���� ���̿� ���� ������ �ִ������̴�.
// 
// �μ��� �ִ������� ��Ŭ���� ȣ������ ���ؼ� ���ϸ� �ȴ�.
//----------------------------------------------------------

//��Ŭ���� ȣ����
int GCD(int num1, int num2)
{
    while (true)
    {
        int r = num1 % num2;
        if (r == 0)
            return num2;

        num1 = num2;
        num2 = r;
    }
}

long long solution(int w, int h) {
    long long answer = 1;

    long long remove = w + h;
    remove -= (w > h) ? GCD(w, h) : GCD(h, w);

    answer = static_cast<long long>(w) * static_cast<long long>(h) - remove;

    return answer;
}

int main()
{
    int w = 8;
    int h = 12;

    long long answer = solution(w, h);

    return 0;
}