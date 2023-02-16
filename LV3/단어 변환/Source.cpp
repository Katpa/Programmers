#include <string>
#include <vector>

using namespace std;

int answer = 50;

int Checker(string str1, string str2)
{
    int output = 0;

    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] == str2[i]) continue;

        output++;
    }

    return output;
}

void DFS(int depth, string current, string target, vector<string> words)
{
    if (depth > answer) return;

    if (target == current)
    {
        if (answer > depth)
            answer = depth;
        return;
    }

    depth++;

    for (string str : words)
    {
        if (Checker(current, str) != 1) continue;

        vector<string> word;
        for (string s : words)
        {
            if (s == str) continue;
            word.push_back(s);
        }
        if (word.size() == 0) continue;
        DFS(depth, str, target, word);
    }

    return;
}

int solution(string begin, string target, vector<string> words)
{
    DFS(0, begin, target, words);

    if (answer == 50) answer = 0;
    return answer;
}

int main()
{
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };

    int answer = solution(begin, target, words);

    return EXIT_SUCCESS;
}