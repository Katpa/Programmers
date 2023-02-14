#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define IN 0
#define OUT 1

bool Comp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int size = routes.size();

    sort(routes.begin(), routes.end(), Comp);

    int out = routes[0][OUT];

    for (int i = 0; i < size; i++)
    {
        if (out >= routes[i][IN])
            out = min(out, routes[i][OUT]);
        else
        {
            out = routes[i][OUT];
            answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> routes = { {-20, -15}, {-14, -5}, {-18, -13}, {-5, -3} };

    int answer = solution(routes);

    return EXIT_SUCCESS;
}