#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<pair<long long, long long>> intersectionPoints;
    long long minX = 9223372036854775807, maxX = -9223372036854775808;
    long long minY = 9223372036854775807, maxY = -9223372036854775808;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
        {
            long long adbc = (long long)line[i][0] * line[j][1] - (long long)line[j][0] * line[i][1];
            if (adbc == 0) continue;

            long double x = ((long double)line[i][1] * line[j][2] - (long double)line[j][1] * line[i][2]) / adbc;
            long double y = ((long double)line[i][2] * line[j][0] - (long double)line[i][0] * line[j][2]) / adbc;

            long long _x = x;
            long long _y = y;

            if (x - _x != 0 || y - _y != 0) continue;

            intersectionPoints.push_back(make_pair(_x, _y));

            if (_x > maxX) maxX = _x;
            if (_x < minX) minX = _x;
            if (_y > maxY) maxY = _y;
            if (_y < minY) minY = _y;
        }
    }

    string emptyStr = "";
    for (long long iter = 0; iter <= maxX - minX; iter++)
        emptyStr += '.';

    vector<string> answer(maxY - minY + 1, emptyStr);

    for (pair<long long, long long> p : intersectionPoints)
    {
        long long x = p.first - minX;
        long long y = answer.size() - 1 - (p.second - minY);

        answer[y][x] = '*';
    }

    return answer;
}