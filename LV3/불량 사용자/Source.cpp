#include <string>
#include <vector>
#include <set>

using namespace std;
set<int> s;
int banLength;
bool check[8];

void DFS(vector<string>& u_id, vector<string>& b_id, int idx, int num)
{
    if (idx == banLength)
    {
        s.emplace(num);
        return;
    }

    for (int i = 0; i < u_id.size(); i++)
    {
        int tempIdx;
        if (u_id[i].size() != b_id[idx].size()) continue;
        if (check[i] == true) continue;

        //문자열 각 인덱스 검사
        for (tempIdx = 0; tempIdx < u_id[i].size(); tempIdx++)
        {
            if (b_id[idx][tempIdx] == '*') continue;
            if (u_id[i][tempIdx] != b_id[idx][tempIdx]) break;
        }

        //비트를 이용해서 각 인덱스 확인 가능함
        if (tempIdx == u_id[i].size())
        {
            check[i] = true;
            DFS(u_id, b_id, idx + 1, num | (1 << i));
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    banLength = banned_id.size();
    DFS(user_id, banned_id, 0, 0);
    return s.size();
}

int main()
{
    vector<string> user_id = { "frodo", "fradi", "crodo", "abc123", "frodoc" };
    vector<string> banned_id = { "fr*d*", "abc1**" };

    int answer = solution(user_id, banned_id);

    return EXIT_SUCCESS;
}