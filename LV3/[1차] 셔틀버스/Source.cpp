#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string TimeToString(int time)
{
    string hour = to_string(time / 60);
    string minute = to_string(time % 60);

    if (hour.size() == 1) hour = "0" + hour;
    if (minute.size() == 1) minute = "0" + minute;

    return hour + ":" + minute;
}

int TimeToInt(string time)
{
    string hour(time.begin(), time.begin() + 2);
    string minute(time.begin() + 3, time.begin() + 5);

    return stoi(hour) * 60 + stoi(minute);
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    vector<int> times(timetable.size());

    for (int i = 0; i < timetable.size(); i++)
        times[i] = TimeToInt(timetable[i]);

    sort(times.begin(), times.end());

    int busTime = TimeToInt("09:00");
    int idx = 0;

    while (n > 1)
    {

        int cnt = 0;

        for (int i = 0; i < m; i++)
        {
            if (times[idx + i] > busTime) break;
            cnt++;
        }

        idx += cnt;

        busTime += t;
        n--;
    }

    int lastTime = busTime + 1;

    if (m > times.size() - idx)
    {
        answer = TimeToString(busTime);
    }
    else
    {
        for (; m > 0 && idx < times.size(); idx++)
        {
            if (times[idx] > busTime) continue;

            lastTime = times[idx];
            m--;
        }

        answer = TimeToString(lastTime - 1);
    }

    return answer;
}

int main()
{
    int n = 1;
    int t = 1;
    int m = 5;
    vector<string> timetable = { "08:00", "08:01", "08:02", "08:03" };

    string answer = solution(n, t, m, timetable);

    return EXIT_SUCCESS;
}