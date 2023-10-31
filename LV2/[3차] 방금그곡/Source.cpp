#include <string>
#include <vector>

using namespace std;

// ��� �ð����� ���� ������ ������� ������ ���ڿ��� ��ȯ�ϴ� �Լ�
// #���� ��� �ҹ��ڷ� ��ȯ
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

// ���� �ð����� ���ϱ� ���� �Է¹޴� �ð� ���ڿ��� int������ �� ������ ��ȯ�ϴ� �Լ�
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
        string strs[4] = {};            // �и��� ���������� ������ ���ڿ� �迭
        string music = "";              // ��� �ð����� ���� ������ ������� ������ ���ڿ�
        int time = 0;                   // ��� �ð��� ������ ����

        // �Է¹��� �������� ���ڿ� �и�
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

        // ��� �ð�(time) �� ��� �ð����� ���� �� ������ ���ڿ�(music) ����
        int times[2] = { GetTime(strs[0]), GetTime(strs[1]) };
        time = times[1] - times[0];
        music = SetMusic(strs[3], time);

        for (int j = 0; j < music.size(); j++)
        {
            // music�� ���� �ε������� ���� �������� �ð��� m�� ���̺��� ª�� ��� ��ȯ
            if (music.size() - j < m.size()) break;

            // ������ �ε������� m�� ������ �˻�
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
            // ������ ��ġ�ϴ� ������ �������� ��츦 ���� ���ǹ�
            if (p.second >= music.size()) continue;

            p.first = strs[2];
            p.second = music.size();
        }
    }

    // p�� �ʱⰪ���� ũ�ٴ� �� ���ǿ� ��ġ�ϴ� ������ �ִ� ����
    if (p.second > 0)
        return p.first;

    // ���� ���� ""(None)" ��ȯ
    return answer;
}