#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = { 0, 0 };
    map<string, int> m;
    int personNum = 0;
    vector<int> wordNum(n, 0);
    char last = words[0][words[0].size() - 1];
    m[words[0]]++;
    wordNum[0]++;

    for (int i = 1; i < words.size(); i++)
    {
        int lastNum = words[i].size() - 1;

        m[words[i]]++;
        personNum = (personNum + 1) % n;
        wordNum[personNum]++;

        if (words[i][0] != last || m[words[i]] > 1)
        {
            answer[0] = personNum + 1;
            answer[1] = wordNum[personNum];
            break;
        }

        last = words[i][lastNum];
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

    vector<int> answer = solution(n, words);

    return EXIT_SUCCESS;
}