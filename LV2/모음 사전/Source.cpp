#include <string>
#include <vector>

using namespace std;

int cnt = -1;
int answer = 0;
string target = "";
string sortWord = "AEIOU";

void DFS(string word)
{
    cnt++;

    if (word == target)
    {
        answer = cnt;
        return;
    }

    if (word.length() >= 5) return;

    for (int i = 0; i < 5; i++)
        DFS(word + sortWord[i]);
}

int solution(string word) {
    target = word;
    DFS("");

    return answer;
}
