using namespace std;

//----------------------------------------------------------
// 두꼭지점을 잇는 대각선에 겹치는 격자의 수는
//      = 가로 길이와 세로 길이의 최대공약수이다.
// 
// 두수의 최대공약수는 유클리드 호제법을 통해서 구하면 된다.
//----------------------------------------------------------

//유클리드 호제법
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