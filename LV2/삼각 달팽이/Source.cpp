#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> triangle;
    int size = n;
    int x = 0, y = -1;
    int num = 1;

    triangle.resize(n);
    for (int i = 0; i < triangle.size(); i++)
        triangle[i].resize(i + 1);

    while (true)
    {
        for (int i = 0; i < size; i++)
        {
            y++;
            triangle[y][x] = num;
            num++;
        }

        for (int q = 0; q < size - 1; q++)
        {
            x++;
            triangle[y][x] = num;
            num++;
        }

        for (int j = 0; j < size - 2; j++)
        {
            y--;
            x--;
            triangle[y][x] = num;
            num++;
        }

        if (size <= 3)
            break;

        size -= 3;
    }

    for (vector<int> vec : triangle)
    {
        for (int num : vec)
            answer.push_back(num);
    }

    return answer;
}

int main()
{
    int n = 4;

    vector<int> answer = solution(n);

    return EXIT_SUCCESS;
}