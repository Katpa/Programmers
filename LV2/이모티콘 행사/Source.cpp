#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer(2, 0);
    vector<vector<int>> prices(emoticons.size(), vector<int>(4, 0));
    vector<int> describers(users.size(), 0);
    int emoticonSize = emoticons.size();

    for (int i = 0; i < emoticonSize; i++)
    {
        prices[i][0] = (float)emoticons[i] * 0.9f;
        prices[i][1] = (float)emoticons[i] * 0.8f;
        prices[i][2] = (float)emoticons[i] * 0.7f;
        prices[i][3] = (float)emoticons[i] * 0.6f;
    }

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i][0] <= 10) users[i][0] = 0;
        else if (users[i][0] <= 20) users[i][0] = 1;
        else if (users[i][0] <= 30) users[i][0] = 2;
        else users[i][0] = 3;
    }

    int idx = 0;
    vector<int> indices(emoticonSize, 0);
    bool isLoop = true;
    while (isLoop)
    {
        vector<int> tmpAnswer(2, 0);
        for (int person = 0; person < users.size(); person++)
        {
            int price = 0;

            for (int p = 0; p < emoticonSize; p++)
            {
                if (users[person][0] <= indices[p])
                    price += prices[p][indices[p]];
            }

            if (price >= users[person][1])
                tmpAnswer[0]++;
            else
                tmpAnswer[1] += price;
        }

        if (tmpAnswer[0] > answer[0] ||
            tmpAnswer[0] == answer[0] && tmpAnswer[1] > answer[1])
            answer = tmpAnswer;

        indices[0]++;
        for (int i = 0; i < emoticonSize; i++)
        {
            if (indices[i] > 3)
            {
                if (i + 1 == emoticonSize)
                {
                    isLoop = false;
                    break;
                }
                indices[i + 1] += indices[i] / 4;
                indices[i] %= 4;
            }
        }
    }

    return answer;
}