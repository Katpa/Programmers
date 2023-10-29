#include <string>
#include <vector>
#include <list>
#include <algorithm>

#define C_HIT 1
#define C_MISS 5

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    if (cacheSize == 0)
    {
        answer = cities.size() * C_MISS;
        return answer;
    }

    list<string> cache;

    for (string& city : cities)
    {
        for (char& ch : city)
            ch = tolower(ch);

        auto iter = find(cache.begin(), cache.end(), city);

        if (iter != cache.end())
        {
            cache.erase(iter);
            cache.push_back(city);

            answer += C_HIT;
        }
        else
        {
            cache.push_back(city);
            if (cache.size() > cacheSize)
                cache.pop_front();

            answer += C_MISS;
        }
    }

    return answer;
}