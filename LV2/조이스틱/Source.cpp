#include <string>
#include <vector>

using namespace std;

int answer = 100000;
string nameStr;

void Finder(string str, int countSum, int curIndex, int moveTo, vector<pair<int, bool>> remainIndex)
{
    for (auto& vec : remainIndex)
    {
        if (vec.first == moveTo)
        {
            vec.second = true;
            break;
        }
    }

    //이동하기
    int tmp1 = abs(moveTo - curIndex);
    int tmp2 = str.size() - curIndex + moveTo;
    int tmp3 = str.size() - moveTo + curIndex;
    int move = min(tmp1, min(tmp2, tmp3));

    curIndex = moveTo;

    //왼쪽 오른쪽 비교하기
    int up = nameStr[curIndex] - 'A';
    int down = 'Z' - nameStr[curIndex] + 1;

    countSum += min(up, down) + move;
    str[curIndex] = nameStr[curIndex];

    if (str == nameStr)
    {
        if (answer > countSum)
            answer = countSum;
        return;
    }

    for (auto index : remainIndex)
        if (!index.second)
            Finder(str, countSum, curIndex, index.first, remainIndex);
}

int solution(string name) {
    string str;
    vector<pair<int, bool>> remain;
    nameStr = name;

    for (int i = 0; i < name.length(); i++)
    {
        str.push_back('A');
        if (name[i] != 'A')
            remain.push_back(make_pair(i, false));
    }

    Finder(str, 0, 0, 0, remain);

    return answer;
}

int main()
{
    string name = "JEROEN";

    int answer = solution(name);

    return EXIT_SUCCESS;
}