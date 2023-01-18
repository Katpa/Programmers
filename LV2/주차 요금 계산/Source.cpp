#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define ONE_HOUR 60

int basicTime;
int basicFee;
int perTime;
int perFee;
int lastTime;

int ToINT(string time)
{
    int output = 0;
    string hour = time.substr(0, 2);
    string minutes = time.substr(3, 2);

    output = stoi(hour) * ONE_HOUR + stoi(minutes);

    return output;
}

void SetRecrod(string str, string& car, int& time)
{
    string timeStr = "";

    for (int i = 0; i < 5; i++)
        timeStr += str[i];
    time = ToINT(timeStr);

    for (int i = 6; i < 10; i++)
        car += str[i];

    if (str.size() == 13)
        time *= -1;

    return;
}

int SetFee(int totalTime)
{
    int output = 0;

    if (totalTime <= 0)
        totalTime += lastTime;


    if (totalTime <= basicTime) return basicFee;

    output += basicFee;
    totalTime -= basicTime;
    output += (int)ceil((float)totalTime / (float)perTime) * perFee;

    return output;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> vec;
    map<string, int> feeList;

    lastTime = ToINT("23:59");
    basicTime = fees[0];
    basicFee = fees[1];
    perTime = fees[2];
    perFee = fees[3];

    for (string str : records)
    {
        string car = "";
        int time = 0;
        SetRecrod(str, car, time);
        vec.push_back(make_pair(car, time));
    }

    for (pair<string, int> p : vec)
        feeList[p.first] += p.second;

    for (pair<string, int> m : feeList)
        answer.push_back(SetFee(m.second));

    return answer;
}

int main()
{
    vector<int> fees = { 180, 5000, 10, 600 };
    vector<string> record = { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" };

    vector<int> answer = solution(fees, record);

    return EXIT_SUCCESS;
}