// ----------------------ó��Ǯ��----------------------
//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//struct Edge
//{
//public:
//    map<int, int> cost;
//};
//
//map<int, int> m;
//vector<Edge> edges;
//int limit;
//
//void DFS(int curPos, int ETA, vector<bool> visited)
//{
//    if (ETA > limit) return;
//    visited[curPos] = true;
//    m[curPos] = ETA;
//
//    for (pair<int, int> edge : edges[curPos].cost)
//    {
//        int target = edge.first;
//
//        if (visited[target]) continue;
//
//        DFS(target, ETA + edge.second, visited);
//    }
//}
//
//int solution(int N, vector<vector<int>> road, int K)
//{
//    int answer = 0;
//    limit = K;
//    vector<bool> visited(N + 1, false);
//    edges.resize(N + 1);
//
//    for (vector<int> vec : road)
//    {
//        if (edges[vec[0]].cost[vec[1]] == 0)
//            edges[vec[0]].cost[vec[1]] = vec[2];
//        else
//            edges[vec[0]].cost[vec[1]] = min(edges[vec[0]].cost[vec[1]], vec[2]);
//
//        if (edges[vec[1]].cost[vec[0]] == 0)
//            edges[vec[1]].cost[vec[0]] = vec[2];
//        else
//            edges[vec[1]].cost[vec[0]] = min(edges[vec[1]].cost[vec[0]], vec[2]);
//    }
//
//    DFS(1, 0, visited);
//
//    m[0]++;
//    answer = m.size() - 1;
//
//    return answer;
//}
// 
// 
//---------------------------------------------------------------------
// ó������ DFS�� DP�� ȥ�� ������� �����ߴµ� 32�� TC�� �ð��ʰ��� �Ǿ���.
// �ᱹ �ذ��� �˰����� Dijkstra�̴�.
// ��湮 ����ó������ �߰� �⺻���� Ʋ���� ū ���̰� ���ٰ� �����ϴµ�
// �ð����⵵���� �� ������� Ŀ�� �̷��Ա��� ū ���̸� ���̴��� �𸣰ڴ�.
// ������ ���� �ͼ� ���� ���� Edge ����ü ó�� ���ʿ��� �ڵ尡 �� ���δ�.
//---------------------------------------------------------------------


#include <vector>
#include <queue>

#define MAX_COST 500001

using namespace std;

vector<pair<int, int>> v[51];
vector<int> cost;

void dijkstra(int k)
{
    int curPos, curCost, nextPos, nextCost;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({ 1, 0 });

    while (!q.empty())
    {
        curPos = q.top().first;
        curCost = q.top().second;
        q.pop();

        for (pair<int, int> p : v[curPos])
        {
            nextPos = p.first;
            nextCost = p.second;

            if (cost[nextPos] > cost[curPos] + nextCost)
            {
                cost[nextPos] = cost[curPos] + nextCost;

                if (cost[nextPos] <= k)
                    q.push({ nextPos, nextCost });
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    cost.resize(N + 1, MAX_COST);

    for (vector<int> vec : road)
    {
        int village1 = vec[0], village2 = vec[1], _cost = vec[2];
        v[village1].push_back(make_pair(village2, _cost));
        v[village2].push_back(make_pair(village1, _cost));
    }

    cost[1] = 0;
    dijkstra(K);

    for (int c : cost)
        if (c <= K)
            answer++;

    return answer;
}

int main()
{
    int N = 6;
    vector<vector<int>> road = { {1,2,1}, {1,3,2}, {2,3,2}, {3,4,3}, {3,5,2}, {3,5,3}, {5,6,1} };
    int K = 4;

    int answer = solution(N, road, K);

    return EXIT_SUCCESS;
}