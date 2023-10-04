#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, queue<int>> nodes;
map<int, int> dist;
vector<bool> visited;

int BFS(int nodeNum, int n)
{
    int output = 0;
    queue<int> curNodes;
    curNodes.push(nodeNum);
    int maxdist = 0;
    dist[1] = 1;

    while (!curNodes.empty())
    {
        int curNum = curNodes.front();
        curNodes.pop();

        while (!nodes[curNum].empty())
        {
            int nextNum = nodes[curNum].front();
            nodes[curNum].pop();

            if (visited[nextNum]) continue;
            visited[nextNum] = true;
            dist[nextNum] = dist[curNum] + 1;
            curNodes.push(nextNum);

            if (dist[nextNum] > maxdist)
                maxdist = dist[nextNum];
        }
    }

    for (int iter = 2; iter <= n; iter++)
        if (dist[iter] == maxdist)
            output++;

    return output;
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    visited.resize(n + 1);
    for (int iter = 0; iter <= n; iter++)
        visited[iter] = false;

    for (vector<int> e : edge)
    {
        nodes[e[0]].push(e[1]);
        nodes[e[1]].push(e[0]);
    }

    visited[1] = true;
    answer = BFS(1, n);

    return answer;
}