#include <string>
#include <vector>
#include <map>

using namespace std;

bool solution(vector<string> phone_book)
{
    map<string, int> m;
    map<int, int> length;

    for (string str : phone_book)
    {
        for (auto l : length)
        {
            string tmp = str.substr(0, l.first);

            if (m[tmp]) return false;
        }

        m[str]++;
        length[str.size()] = length.size();
    }

    return true;
}

int main()
{
    vector<string> phone_book = { "119", "97674223", "1195524421" };

    bool answer = solution(phone_book);

    return EXIT_SUCCESS;
}