#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int total = brown + yellow;
    int wh = (brown + 4) >> 1;

    for (int height = 3; height < wh; height++)
    {
        int width = wh - height;

        if (wh == width + height && height * width == total)
        {
            answer.push_back(width);
            answer.push_back(height);

            break;
        }
    }

    return answer;
}

int main()
{
    int brown = 10;
    int yellow = 2;
    vector<int> answer = solution(brown, yellow);

    return EXIT_SUCCESS;
}