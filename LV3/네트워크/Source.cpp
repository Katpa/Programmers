#include <string>
#include <vector>

using namespace std;

void DFS(int idx, vector<bool>& visited, vector<vector<int>> computers)
{
    if (visited[idx]) return;

    visited[idx] = true;

    for (int i = 0; i < computers[idx].size(); i++)
    {
        if (!computers[idx][i]) continue;

        DFS(i, visited, computers);
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;

        answer++;

        DFS(i, visited, computers);
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<vector<int>> computers = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };

    int answer = solution(n, computers);

    return EXIT_SUCCESS;
}