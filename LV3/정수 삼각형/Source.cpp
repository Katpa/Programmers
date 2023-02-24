#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int layers = triangle.size();

    for (int i = layers - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    answer = triangle[0][0];

    return answer;
}

int main()
{
    vector<vector<int>> triangle = { {7}, {3, 8}, {2, 7, 4, 4}, {4, 5, 2, 6, 5} };

    int answer = solution(triangle);

    return EXIT_SUCCESS;
}