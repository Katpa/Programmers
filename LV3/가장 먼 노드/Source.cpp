#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, queue<int>> nodes;
vector<bool> visited;

int BFS(int nodeNum, int n)
{
    int output = 0;
    queue<int> curNodes;
    curNodes.push(nodeNum);
    for (int iter = 1; iter <= n; iter++)
    {
        vector<int> collector;
        output = curNodes.size();

        while (!curNodes.empty())
        {
            vector<int> nextNums;
            int node = curNodes.front();
            curNodes.pop();
            while (!nodes[node].empty())
            {
                int nextNodeNum = nodes[node].front();
                nodes[node].pop();
                if (visited[nextNodeNum]) continue;
                visited[nextNodeNum] = true;
                nextNums.push_back(nextNodeNum);
            }

            for (int num : nextNums)
                collector.push_back(num);
        }
        if (collector.size() == 0) return output;
        for (int c : collector)
            curNodes.push(c);
    }
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