#include <string>
#include <vector>

using namespace std;
vector<vector<int>> wire;
int length;

int DFS(int idx, vector<bool>& excep)
{
    for (int i = 0; i < wire.size(); i++)
    {
        if (excep[i]) continue;

        if (idx == wire[i][0])
        {
            excep[i] = true;
            DFS(wire[i][1], excep);
        }
        else if (idx == wire[i][1])
        {
            excep[i] = true;
            DFS(wire[i][0], excep);
        }
    }

    int num = 0;
    for (bool b : excep)
        if (b)
            num++;

    return num;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;

    wire = wires;
    length = wires.size();
    for (int i = 0; i < length; i++)
    {
        vector<bool> excep1(length, false);
        excep1[i] = true;
        vector<bool> excep2(length, false);
        excep2[i] = true;
        int a = wires[i][0];
        int b = wires[i][1];

        int gap = abs(DFS(a, excep1) - DFS(b, excep2));

        if (gap < answer)
            answer = gap;
    }

    return answer;
}

int main()
{
    int n = 9;
    vector<vector<int>> wires = { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} };

    int answer = solution(n, wires);

    return EXIT_SUCCESS;
}