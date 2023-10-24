// Dijkstra

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 20000000
#define NODE first 
#define COST second 

using namespace std;

void Dijkstra(vector<int>& taxi_cost, vector<vector<int>>& graph, int& n, int& start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ start, 0 });
    taxi_cost[start] = 0;

    while (!pq.empty())
    {
        int curNode = pq.top().NODE;
        int curCost = pq.top().COST;
        pq.pop();

        for (int i = 1; i <= n; ++i)
        {
            if (graph[curNode][i] == 0)
                continue;

            if (taxi_cost[i] > curCost + graph[curNode][i])
            {
                taxi_cost[i] = curCost + graph[curNode][i];
                pq.push({ i, curCost + graph[curNode][i] });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = INF;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (vector<int> vec : fares)
    {
        graph[vec[0]][vec[1]] = vec[2];
        graph[vec[1]][vec[0]] = vec[2];
    }

    // s를 시작지점으로 한 모든 노드까지의 cost
    vector<int> costFromStart(n + 1, INF);
    Dijkstra(costFromStart, graph, n, s);

    // a를 시작지점으로 한 모든 노드까지의 cost
    vector<int> costFromA(n + 1, INF);
    Dijkstra(costFromA, graph, n, a);

    // s를 시작지점으로 한 모든 노드까지의 cost
    vector<int> costFromB(n + 1, INF);
    Dijkstra(costFromB, graph, n, b);

    for (int i = 1; i <= n; ++i)
    {
        int result = costFromStart[i] + costFromA[i] + costFromB[i];
        if (answer > result)
            answer = result;
    }

    return answer;
}