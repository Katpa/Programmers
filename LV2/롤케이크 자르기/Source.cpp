#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int length = topping.size();
    map<int, int> old, young;

    for (int num : topping)
        young[num]++;

    //i 자르는 위치  (i와 i - 1 사이를 자름)
    for (int i = 0; i < length; i++)
    {
        old[topping[i]]++;
        young[topping[i]]--;
        if (young[topping[i]] == 0)
            young.erase(topping[i]);

        if (old.size() == young.size())
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> topping = { 1, 2, 1, 3, 1, 4, 1, 2 };

    int answer = solution(topping);

    return EXIT_SUCCESS;
}