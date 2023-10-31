#include <string>
#include <vector>

using namespace std;

// 재생 시간동안 나온 음들을 순서대로 나열한 문자열을 반환하는 함수
// #음의 경우 소문자로 변환
string SetMusic(string str, int playingTime, bool isM = false)
{
    string output = "";
    string tmp = "";
    for (char c : str)
    {
        if (c == '#')
        {
            tmp.back() = tolower(tmp.back());
            if (isM)
                playingTime--;
        }
        else
            tmp += c;
    }

    for (int i = 0; i < playingTime; i++)
        output += tmp[i % tmp.size()];

    return output;
}

// 편한 시간차를 구하기 위해 입력받는 시간 문자열을 int형으로 분 값으로 반환하는 함수
int GetTime(string time)
{
    string hour(time.begin(), time.begin() + 2);
    string mins(time.begin() + 3, time.begin() + 5);

    return stoi(hour) * 60 + stoi(mins);
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    pair<string, int> p = { "", 0 };
    m = SetMusic(m, m.size(), true);

    for (int i = 0; i < musicinfos.size(); i++)
    {
        string strs[4] = {};            // 분리된 음악정보를 저장할 문자열 배열
        string music = "";              // 재생 시간동안 나온 음들을 순서대로 저장할 문자열
        int time = 0;                   // 재생 시간을 저장할 변수

        // 입력받은 음악정보 문자열 분리
        int index = 0;
        for (int j = 0; j < musicinfos[i].size(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                index++;
                continue;
            }
            strs[index] += musicinfos[i][j];
        }

        // 재생 시간(time) 및 재생 시간동안 나온 음 나열된 문자열(music) 저장
        int times[2] = { GetTime(strs[0]), GetTime(strs[1]) };
        time = times[1] - times[0];
        music = SetMusic(strs[3], time);

        for (int j = 0; j < music.size(); j++)
        {
            // music의 현재 인덱스부터 끝날 때까지의 시간이 m의 길이보다 짧을 경우 반환
            if (music.size() - j < m.size()) break;

            // 현재의 인덱스부터 m과 같은지 검사
            bool isAnswer = true;
            for (int q = 0; q < m.size(); q++)
            {
                if (music[j + q] != m[q])
                {
                    isAnswer = false;
                    break;
                }
            }

            if (isAnswer == false) continue;
            // 조건이 일치하는 음악이 여러개일 경우를 위한 조건문
            if (p.second >= music.size()) continue;

            p.first = strs[2];
            p.second = music.size();
        }
    }

    // p의 초기값보다 크다는 건 조건에 일치하는 음악이 있는 조건
    if (p.second > 0)
        return p.first;

    // 없는 경우는 ""(None)" 반환
    return answer;
}