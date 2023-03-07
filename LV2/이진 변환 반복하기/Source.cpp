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
    });                                                         //s�� �������� ��ȯ

    while (true)
    {
        if (bin == vector<bool>{true}) break;
        int ones = count(bin.cbegin(), bin.cend(), true);    //1������ ��
        zeros += bin.size() - ones;                          //0������ ��
        bin.clear();
        while (ones > 0)
        {
            bin.emplace_back(ones % 2);
            ones /= 2;
        }                                                       //1������ 2������ �ٲ�. ������ �Ųٷ����� ��꿡�� �������
        ++num_transform;                                        //������ȯ Ƚ�� ���
    }
    return { num_transform,zeros };
}

int main()
{
    string s = "110010101001";
    vector<int> answer = solution(s);

    return EXIT_SUCCESS;
}