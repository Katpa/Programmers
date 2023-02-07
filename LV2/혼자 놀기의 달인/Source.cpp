#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ReturnCardCount(vector<pair<int, bool>> cards);

int solution(vector<int> c) {
    int answer = 0;
    vector<pair<int, bool>> cards(c.size());

    for (int i = 0; i < cards.size(); i++)
        cards[i] = make_pair(c[i], false);

    answer = ReturnCardCount(cards);

    return answer;
}

int ReturnCardCount(vector<pair<int, bool>> cards)
{
    vector<int> bestSum;
    int first = 0, second = 0;
    int nextCard;
    bool isLoop;

    for (int i = 0; i < cards.size(); i++)
    {
        vector<int> seconds;
        first = 0;
        isLoop = true;
        nextCard = i;

        for (int i = 0; i < cards.size(); i++)
            cards[i].second = false;

        while (isLoop)
        {
            cards[nextCard].second = true;
            nextCard = cards[nextCard].first - 1;
            first++;

            if (cards[nextCard].second)
                break;
        }

        for (int j = 0; j < cards.size(); j++)
        {
            if (cards[j].second) continue;

            vector<pair<int, bool>> tmpCards = cards;
            second = 0;
            isLoop = true;
            nextCard = j;

            while (isLoop)
            {
                tmpCards[nextCard].second = true;
                nextCard = tmpCards[nextCard].first - 1;
                second++;

                if (tmpCards[nextCard].second)
                {
                    seconds.push_back(second);
                    second = 0;
                    break;
                }
            }

            second = *max_element(seconds.begin(), seconds.end());
        }
        bestSum.push_back(first * second);
    }

    return *max_element(bestSum.begin(), bestSum.end());
}

int main()
{
    vector<int> c = { 8, 6, 3, 7, 2, 5, 1, 4 };

    int answer = solution(c);

    return EXIT_SUCCESS;
}