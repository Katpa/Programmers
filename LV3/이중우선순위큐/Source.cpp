#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

bool isMax = true;

void Split(string str, char delChar, vector<pair<string, int>>& output)
{
    bool isFirst = true;
    stringstream ss;
    ss.str(str);

    string tmpStr;
    pair<string, int> tmpPair;
    while (getline(ss, tmpStr, delChar))
    {
        if (isFirst)
        {
            tmpPair.first = tmpStr;
            isFirst = !isFirst;
        }
        else
            tmpPair.second = stoi(tmpStr);
    }

    output.push_back(tmpPair);

    return;
}

bool Comp(int a, int b)
{
    if (isMax)
        return a < b;
    else
        return a > b;
}

void ModifyQue(queue<int>& q)
{
    priority_queue<int, vector<int>, bool(*)(int, int)> pq(Comp);

    while (!q.empty())
    {
        pq.push(q.front());
        q.pop();
    }

    pq.pop();

    while (!pq.empty())
    {
        q.push(pq.top());
        pq.pop();
    }
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;
    vector<pair<string, int>> vec;
    queue<int> q;

    for (string oper : operations)
        Split(oper, ' ', vec);

    for (pair<string, int> pair : vec)
    {
        if (pair.first == "I")
        {
            q.push(pair.second);
        }
        else
        {
            if (q.empty()) continue;

            if (pair.second > 0)
                isMax = true;
            else
                isMax = false;

            ModifyQue(q);
        }
    }

    if (q.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        priority_queue<int, vector<int>> pqMax;
        priority_queue<int, vector<int>, greater<int>> pqMin;
        while (!q.empty())
        {
            pqMax.push(q.front());
            pqMin.push(q.front());
            q.pop();
        }
        answer.push_back(pqMax.top());
        answer.push_back(pqMin.top());
    }

    return answer;
}

int main()
{
    vector<string> operations = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };

    vector<int> answer = solution(operations);

    return EXIT_SUCCESS;
}