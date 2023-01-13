#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> vec(arr2[0].size());
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int tmpNum = 0;
            for (int q = 0; q < arr2.size(); q++)
            {
                tmpNum += arr1[i][q] * arr2[q][j];
            }
            vec[j] = tmpNum;
        }
        answer.push_back(vec);
    }

    return answer;
}

int main()
{
    vector<vector<int>> arr1 = { {1, 4}, {3, 2}, {4, 1} };
    vector<vector<int>> arr2 = { {3, 3}, {3, 3} };
    vector<vector<int>> answer = solution(arr1, arr2);

    return EXIT_SUCCESS;
}