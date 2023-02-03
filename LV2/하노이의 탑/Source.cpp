#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void MoveBlock(int start, int mid, int dest, int n)
{
    if (!n) return;

    MoveBlock(start, dest, mid, n - 1);
    answer.push_back({ start, dest });
    MoveBlock(mid, start, dest, n - 1);
}

vector<vector<int>> solution(int n) {
    MoveBlock(1, 2, 3, n);

    return answer;
}

int main()
{
    int n = 2;

    vector<vector<int>> answer = solution(n);

    return EXIT_SUCCESS;
}