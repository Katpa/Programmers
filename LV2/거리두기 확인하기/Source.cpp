#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct Node
{
public:
    int x, y;
    int cost, dist;

    Node(int _x, int _y, int c, int d)
        :x(_x), y(_y), cost(c), dist(d)
    {}
};

bool Check(vector<string> place)
{
    queue<pair<int, int>> q;

    for (int y = 0; y < place.size(); y++)
    {
        for (int x = 0; x < place[y].size(); x++)
        {
            if (place[y][x] != 'P') continue;
            q.push(make_pair(x, y));
        }
    }

    while (!q.empty())
    {
        vector<vector<bool>> visited(5, vector<bool>(5, false));
        queue<Node> nodes;
        Node startNode(q.front().first, q.front().second, 0, 0);
        visited[startNode.y][startNode.x] = true;
        nodes.push(startNode);

        while (!nodes.empty())
        {
            Node curNode = nodes.front();
            nodes.pop();

            if (curNode.cost == 2) continue;
            if (curNode.dist > 2) continue;

            for (int i = 0; i < 4; i++)
            {
                int x = curNode.x + dx[i];
                int y = curNode.y + dy[i];

                if (x < 0 || x >= 5 || y < 0 || y >= 5) continue;

                if (visited[y][x] == true) continue;
                visited[y][x] = true;

                if (place[y][x] == 'X') continue;
                if (place[y][x] == 'P' && curNode.cost < 2)
                {
                    return false;
                }

                nodes.push(Node(x, y, curNode.cost + 1, curNode.dist + 1));
            }
        }

        q.pop();
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        if (Check(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}