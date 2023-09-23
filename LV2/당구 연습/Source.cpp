#include <string>
#include <vector>
#include <math.h>

using namespace std;

pair<int, int> scale;

int GetPathLength(pair<int, int> start, pair<int, int> end)
{
    double output = pow((double)start.first - (double)end.first, 2) + pow((double)start.second - (double)end.second, 2);
    return static_cast<int>(output);
}

int GetMinPath(pair<int, int> start, pair<int, int> end)
{
    int minLength = INT_MAX;
    vector<pair<int, int>> balls;

    //up
    if (!(start.first == end.first && start.second < end.second)) balls.push_back(make_pair(end.first, scale.second * 2 - end.second));
    //down
    if (!(start.first == end.first && start.second > end.second)) balls.push_back(make_pair(end.first, end.second * -1));
    //right
    if (!(start.second == end.second && start.first < end.first)) balls.push_back(make_pair(scale.first * 2 - end.first, end.second));
    //left
    if (!(start.second == end.second && start.first > end.first)) balls.push_back(make_pair(end.first * -1, end.second));

    int curLength;
    for (pair<int, int> ball : balls)
    {
        curLength = GetPathLength(start, ball);
        if (minLength > curLength) minLength = curLength;
    }

    return minLength;
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    scale = make_pair(m, n);

    for (vector<int> ball : balls)
    {
        answer.push_back(GetMinPath(make_pair(startX, startY), make_pair(ball[0], ball[1])));
    }

    return answer;
}