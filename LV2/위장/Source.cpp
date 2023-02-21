#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> presets;

    for (vector<string> vec : clothes)
    {
        presets[vec[1]]++;
    }

    for (auto preset : presets)
    {
        answer *= preset.second + 1;
    }

    return answer - 1;
}

int main()
{
    vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };

    int answer = solution(clothes);

    return EXIT_SUCCESS;
}