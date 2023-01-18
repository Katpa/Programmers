#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> dictionary;
int lastKey = 0;

int GetNum(string msg, int& curPos)
{
    string key;
    key += msg[curPos];
    int output = 0;
    bool isLoop = true;

    while (isLoop)
    {
        if (msg.size() == curPos) break;

        if (dictionary[key] > 0)
        {
            output = dictionary[key];
            curPos++;
            key += msg[curPos];
        }
        else
            isLoop = false;
    }

    dictionary[key] = lastKey;
    lastKey++;

    return output;
}

vector<int> solution(string msg) {
    vector<int> answer;

    /// A~Z ют╥б
    for (; lastKey < 26; lastKey++)
    {
        string key = "";
        key += ('A' + lastKey);
        int number = lastKey + 1;
        dictionary[key] = number;
    }
    lastKey++;

    int curPos = 0;

    while (curPos < msg.size())
    {
        answer.push_back(GetNum(msg, curPos));
    }

    return answer;
}

int main()
{
    string msg = "KAKAO";

    vector<int> answer = solution(msg);

    return EXIT_SUCCESS;
}