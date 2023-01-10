#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int Square(int num)
{
    int output = 1;

    for (int i = 0; i < num; i++)
        output *= 10;

    return output;
}

string solution(string s) {
    string answer = "";
    vector<int> nums;
    vector<int>inputNum;
    bool isMinus = false;

    s += " ";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            int tmpNum = 0;

            //�Էµ� ���� 10 �̻� Ȥ�� -10 ������ ���� ���� ����ó��
            for (int j = 0; j < inputNum.size(); j++)
                tmpNum += inputNum[j] * Square(inputNum.size() - (j + 1));

            if (isMinus)
                tmpNum *= -1;

            nums.push_back(tmpNum);

            inputNum.clear();
            isMinus = false;
        }
        else if (s[i] == '-')
        {
            //���� ����ó��
            isMinus = true;
            continue;
        }
        else
        {
            inputNum.push_back((int)s[i] - 48);
        }
    }

    sort(nums.begin(), nums.end());

    answer = to_string(nums[0]) + " " + to_string(nums[nums.size() - 1]);

    return answer;
}

/*
int main()
{
    string s = "1 2 3 4";
    string answer = solution(s);

    return EXIT_SUCCESS;
}
*/