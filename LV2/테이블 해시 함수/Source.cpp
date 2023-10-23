#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int value = 0;

bool Cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[value] == b[value])
        return a[0] > b[0];

    return a[value] < b[value];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    int answer = 0;
    value = col - 1;
    sort(data.begin(), data.end(), Cmp);

    vector<int> sums;
    for (int i = row_begin - 1; i < row_end; i++)
    {
        int sum = 0;
        for (int j = 0; j < data[i].size(); j++)
        {
            sum += data[i][j] % (i + 1);
        }

        sums.push_back(sum);
    }

    answer = sums[0];
    for (int i = 1; i < sums.size(); i++)
    {
        answer = answer ^ sums[i];
    }

    return answer;
}