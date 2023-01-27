#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = -1;
    for (int i = 0; i < number.size() - k; i++) {
        char max = ' ';
        for (int j = index + 1; j <= k + i; j++) {
            if (max < number[j]) {
                max = number[j];
                index = j;
            }
        }

        answer += max;
    }
    return answer;
}

int main()
{
    string number = "1924";
    int k = 2;

    string answre = solution(number, k);

    return EXIT_SUCCESS;
}