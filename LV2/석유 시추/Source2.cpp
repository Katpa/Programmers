#include <string>
#include <vector>
#include <iostream>


using namespace std;

vector<vector<int>> copy_land;
vector<int> m;
int miny, maxy;

int get_oil(int x, int y) {
    if (x < 0 || x >= copy_land.size() || y < 0 || y >= copy_land[0].size()) return 0;
    if (copy_land[x][y] == 0) return 0;

    copy_land[x][y] = 0;
    if (miny > y) miny = y;
    else if (maxy < y) maxy = y;
    int a = get_oil(x - 1, y);
    int b = get_oil(x + 1, y);
    int c = get_oil(x, y - 1);
    int d = get_oil(x, y + 1);

    return a + b + c + d + 1;
}

int solution(vector<vector<int>> land) {
    copy_land = land;
    for (int i = 0; i < land[0].size(); i++) m.push_back(0);

    int answer = 0;

    for (int i = 0; i < copy_land.size(); i++) {
        for (int j = 0; j < copy_land[i].size(); j++) {
            if (copy_land[i][j] == 0) continue;
            else {
                miny = j, maxy = j;
                int tmp_oil = get_oil(i, j);
                for (int k = miny; k <= maxy; k++) m[k] += tmp_oil;
            }
        }
    }
    for (int i = 0; i < m.size(); i++) if (m[i] > answer) answer = m[i];
    return answer;
}