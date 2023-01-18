#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> idList;
    map<int, pair<string, string>> cmdList;

    for (int i = 0; i < record.size(); i++)
    {
        int index = 0;
        string tmpStr[3];

        for (char ch : record[i])
        {
            if (ch == ' ')
                index++;
            else
                tmpStr[index] += ch;
        }

        if (tmpStr[0] != "Leave")
            idList[tmpStr[1]] = tmpStr[2];
        cmdList[i].first = tmpStr[1];
        cmdList[i].second = tmpStr[0];
    }

    for (int i = 0; i < cmdList.size(); i++)
    {
        string tmpStr = idList[cmdList[i].first] + "님이 ";

        if (cmdList[i].second == "Enter")
            tmpStr += "들어왔습니다.";
        else if (cmdList[i].second == "Leave")
            tmpStr += "나갔습니다.";
        else
            continue;

        answer.push_back(tmpStr);
    }

    return answer;
}

int main()
{
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };

    vector<string> answer = solution(record);

    return EXIT_SUCCESS;
}