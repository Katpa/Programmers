#include <string>
#include <vector>

using namespace std;

vector<int> Count(vector<vector<int>> arr);
vector<int> DFS(vector<vector<int>> arr);

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    answer = DFS(arr);

    return answer;
}

vector<int> Count(vector<vector<int>> arr)
{
    int one = 0, zero = 0;
    for (vector<int> a : arr)
    {
        for (int num : a)
        {
            if (num) one++;
            else    zero++;
        }
    }
    return { zero, one };
}

vector<int> DFS(vector<vector<int>> arr)
{
    vector<int> output(2, 0);
    vector<int> countArr = Count(arr);
    int h = arr[0].size();
    int v = arr.size();


    if (h == 1)                                     return countArr;
    else if (countArr[0] == 0 || countArr[1] == 0)   countArr[0] ? output[0]++ : output[1]++;
    else
    {
        int half = h >> 1;
        vector<vector<vector<int>>> quad(4, vector<vector<int>>(half, vector<int>(half)));
        vector<int> cnt(4, 0);

        for (int y = 0; y < v; y++)
        {
            bool isOverY = half <= y;
            for (int x = 0; x < h; x++)
            {
                bool isOverX = half <= x;

                if (isOverX)
                {
                    if (isOverY)
                    {
                        quad[3][cnt[3] / half][cnt[3] % half] = arr[y][x];
                        cnt[3]++;
                    }
                    else
                    {
                        quad[2][cnt[2] / half][cnt[2] % half] = arr[y][x];
                        cnt[2]++;
                    }
                }
                else
                {
                    if (isOverY)
                    {
                        quad[1][cnt[1] / half][cnt[1] % half] = arr[y][x];
                        cnt[1]++;
                    }
                    else
                    {
                        quad[0][cnt[0] / half][cnt[0] % half] = arr[y][x];
                        cnt[0]++;
                    }
                }
            }
        }

        vector<int> tmpVec;
        for (int iter = 0; iter < quad.size(); iter++)
        {
            tmpVec = DFS(quad[iter]);
            output[0] += tmpVec[0];
            output[1] += tmpVec[1];
        }
    }
    return output;
}