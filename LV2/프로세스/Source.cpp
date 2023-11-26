#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> pri, int location) {

    queue<pair<int, int>> que;
    int index = 0;
    vector<int> sortedPri = pri;
    sort(sortedPri.rbegin(), sortedPri.rend());

    int length = pri.size();

    for (int i = 0; i < length; i++)
    {
        que.push(make_pair(pri[i], i));
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (que.front().first == sortedPri[index])
            {
                index++;
                if (que.front().second == location)
                    return index;

                que.pop();

                break;
            }
            else
            {
                que.push(que.front());
                que.pop();
            }
        }
    }
}