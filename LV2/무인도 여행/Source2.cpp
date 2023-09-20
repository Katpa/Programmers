#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
vector<vector<bool>> visited;

int dfs(int x, int y, vector<string>& maps)
{
    int food = maps[x][y] - '0';

    for (int k = 0; k < 4; k++) {
        int nextX = x + dx[k];
        int nextY = y + dy[k];
        if (0 > nextX || nextX >= maps.size() || 0 > nextY || nextY >= maps[0].size()) continue;
        if (visited[nextX][nextY] || maps[nextX][nextY] == 'X') continue;
        visited[nextX][nextY] = true;
        food += dfs(nextX, nextY, maps);
    }

    return food;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    visited = vector<vector<bool>>(maps.size(), vector<bool>(maps[0].size(), false));

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (visited[i][j] || maps[i][j] == 'X') continue;
            
            visited[i][j] = true;
            answer.push_back(dfs(i, j, maps));
        }
    }

    if (answer.empty()) return { -1 };

    sort(answer.begin(), answer.end());

    return answer;
}