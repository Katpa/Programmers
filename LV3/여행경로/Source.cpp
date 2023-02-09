#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<bool> visit(1000000, false);
bool flag = false;
int cnt = 0;

void DFS(string cur, vector<vector<string>> tickets)
{
    if (cnt == tickets.size()) flag = true;

    answer.push_back(cur);

    for (int i = 0; i < tickets.size(); i++)
    {
        if (visit[i]) continue;
        if (cur != tickets[i][0]) continue;

        visit[i] = true;
        cnt++;
        DFS(tickets[i][1], tickets);

        if (flag) continue;

        answer.pop_back();
        visit[i] = false;
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets);

    return answer;
}

int main()
{
    vector<vector<string>> tickets = { {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} };

    vector<string> answer = solution(tickets);

    return EXIT_SUCCESS;
}