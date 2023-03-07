#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s)
{
    int zeros{ 0 }, num_transform{ 0 }; vector<bool> bin;
    for_each(s.cbegin(), s.cend(), [&bin](const char c)
    {
        bin.emplace_back(c == '1');
    });                                                         //s를 이진수로 변환

    while (true)
    {
        if (bin == vector<bool>{true}) break;
        int ones = count(bin.cbegin(), bin.cend(), true);    //1갯수를 셈
        zeros += bin.size() - ones;                          //0갯수를 셈
        bin.clear();
        while (ones > 0)
        {
            bin.emplace_back(ones % 2);
            ones /= 2;
        }                                                       //1갯수를 2진수로 바꿈. 순서는 거꾸로지만 계산에는 영향없음
        ++num_transform;                                        //이진변환 횟수 기록
    }
    return { num_transform,zeros };
}

int main()
{
    string s = "110010101001";
    vector<int> answer = solution(s);

    return EXIT_SUCCESS;
}