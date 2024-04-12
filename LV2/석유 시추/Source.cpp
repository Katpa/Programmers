#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int sizeX, sizeY;
int oilCnt = 0;
int oilSize = 0;

int dirx[4] = { 0, 0, 1, -1 };
int diry[4] = { 1, -1, 0, 0 };

vector<vector<int>> m;                          // 좌표의 덩어리 순서
vector<int> sizes;                              // 해당 순서의 오일 덩어리 크기

void Search(int x, int y, const vector<vector<int>>& land)
{
    if (x == sizeX || x < 0 || y == sizeY || y < 0) return;
    if (land[y][x] == 0) return;
    if (m[y][x] != -1) return;

    m[y][x] = oilCnt;
    oilSize++;

    for (int i = 0; i < 4; i++)
    {
        Search(x + dirx[i], y + diry[i], land);
    }

    return;
}

int solution(vector<vector<int>> land)
{
    int answer = 0;

    sizeX = land[0].size();
    sizeY = land.size();

    m.resize(sizeY);
    for (int i = 0; i < sizeY; i++)
        m[i] = vector<int>(sizeX, -1);

    for (int x = 0; x < sizeX; x++)
    {
        int sum = 0;
        unordered_map<int, bool> visited;

        for (int y = 0; y < sizeY; y++)
        {
            if (land[y][x] == 0) continue;

            // 이미 탐색을 마친 덩어리일 경우
            if (m[y][x] >= 0)
            {
                if (visited[m[y][x]]) continue;
                sum += sizes[m[y][x]];
                visited[m[y][x]] = true;
            }
            // 아직 탐색을 마치지 못한 덩어리
            else
            {
                Search(x, y, land);
                sizes.push_back(oilSize);
                sum += oilSize;
                visited[oilCnt] = true;

                oilSize = 0;
                oilCnt++;
            }
        }

        if (sum > answer)
            answer = sum;
    }

    return answer;
}