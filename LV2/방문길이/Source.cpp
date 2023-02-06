#include <string>
#include <map>

using namespace std;

void Move(int& var, int a)
{
    var += a;

    if (var > 5) var = 5;
    if (var < -5) var = -5;
}

int solution(string dirs) {
    int length = dirs.size();
    map<string, int> m;
    int x = 0, y = 0;

    for (int idx = 0; idx < length; idx++)
    {
        char curDir = dirs[idx];
        int prevX = x, prevY = y;

        switch (curDir)
        {
        case 'U':
            Move(y, 1);
            break;
        case 'D':
            Move(y, -1);
            break;
        case 'L':
            Move(x, -1);
            break;
        case 'R':
            Move(x, 1);
            break;
        }

        if (prevX != x || prevY != y)
        {
            string key = "";
            key += to_string(prevX) + to_string(prevY) + to_string(x) + to_string(y);
            m[key]++;

            key = to_string(x) + to_string(y) + to_string(prevX) + to_string(prevY);
            m[key]++;
        }
    }
    int answer = m.size() >> 1;
    return answer;
}

int main()
{
    string dirs = "ULURRDLLU";

    int answer = solution(dirs);

    return EXIT_SUCCESS;
}