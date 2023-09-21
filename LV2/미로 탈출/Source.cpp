#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int x = 0;
    int y = 0;
    int cost = 0;

    bool operator==(const Node& b) { return this->x == b.x && this->y == b.y; }
};
Node Size;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<Node> BFS(Node curNode, vector<vector<bool>>& visited, const vector<string> maps)
{
    vector<Node> nodes;

    for (int iter = 0; iter < 4; iter++)
    {
        Node nextNode = { curNode.x + dx[iter], curNode.y + dy[iter], curNode.cost + 1 };

        if (nextNode.x < 0 || nextNode.x >= Size.x) continue;
        if (nextNode.y < 0 || nextNode.y >= Size.y) continue;
        if (maps[nextNode.y][nextNode.x] == 'X') continue;
        if (visited[nextNode.y][nextNode.x]) continue;

        visited[nextNode.y][nextNode.x] = true;
        nodes.push_back(nextNode);
    }

    return nodes;
}

int GetPath(Node start, Node end, const vector<string> maps)
{
    queue<Node> nodes;
    nodes.push(start);

    vector<vector<bool>> visited(Size.y, vector<bool>(Size.x, false));
    visited[start.y][start.y] = true;

    while (!nodes.empty())
    {
        vector<Node> linked;
        Node curNode = nodes.front();
        nodes.pop();

        linked = BFS(curNode, visited, maps);
        for (Node& node : linked)
        {
            if (node == end)
                return node.cost;
            else
                nodes.push(node);
        }
    }

    return 0;
}

int solution(vector<string> maps)
{
    Size.x = maps[0].size();
    Size.y = maps.size();
    Node start, lever, exit;

    for (int y = 0; y < Size.y; y++)
    {
        for (int x = 0; x < Size.x; x++)
        {
            switch (maps[y][x])
            {
            case 'S':
                start = { x, y, 0 };
                break;
            case 'L':
                lever = { x, y, 0 };
                break;
            case 'E':
                exit = { x, y, 0 };
                break;
            }
        }
    }

    int toLever = GetPath(start, lever, maps);
    if (!toLever) return -1;
    int toExit = GetPath(lever, exit, maps);
    if (!toExit) return -1;

    return toLever + toExit;
}