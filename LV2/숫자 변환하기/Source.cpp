#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec(1000001, 1000001);

void BFS(int x, int targetNum, int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(x);

    while (!q.empty())
    {
        int num = q.top();
        q.pop();

        if (num > targetNum) break;

        if (num + n < 1000001 && vec[num + n] > vec[num] + 1)
        {
            vec[num + n] = vec[num] + 1;
            q.push(num + n);
        }
        if (num * 2 < 1000001 && vec[num * 2] > vec[num] + 1)
        {
            vec[num * 2] = vec[num] + 1;
            q.push(num * 2);
        }
        if (num * 3 < 1000001 && vec[num * 3] > vec[num] + 1)
        {
            vec[num * 3] = vec[num] + 1;
            q.push(num * 3);
        }
    }

    return;
}

int solution(int x, int y, int n)
{
    if (x == y) return 0;

    vec[x] = 0;

    BFS(x, y, n);

    return vec[y] == 1000001 ? -1 : vec[y];
}

int main()
{
    int x = 10;
    int y = 40;
    int n = 5;

    int answer = solution(x, y, n);

    return EXIT_SUCCESS;
}