#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];

int getParent(int node)
{
    if (parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(costs.begin(), costs.end(), cmp);

    for (int i = 0; i < costs.size(); i++) {
        int start = getParent(costs[i][0]);
        int end = getParent(costs[i][1]);
        int cost = costs[i][2];

        if (start == end) continue;

        answer += cost;
        parent[end] = start;
    }

    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> costs = { {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8} };

    int answer = solution(n, costs);

    return EXIT_SUCCESS;
}