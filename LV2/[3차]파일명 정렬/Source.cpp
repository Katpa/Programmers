#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct File
{
    File(string str, int i)
        :idx(i)
    {
        int iter = 0;
        for (; iter < str.size(); iter++)
        {
            if ('0' > str[iter] || '9' < str[iter])
                head += tolower(str[iter]);
            else
                break;
        }

        string numStr = "";

        for (; iter < str.size(); iter++)
        {
            if ('0' <= str[iter] && '9' >= str[iter])
                numStr += str[iter];
            else
                break;
        }
        num = stoi(numStr);
    }

    string head;
    int num;
    int idx;
};

bool Cmp(const File& a, const File& b)
{
    if (a.head == b.head) {
        if (a.num == b.num) {
            return a.idx < b.idx;
        }
        else {
            return a.num < b.num;
        }
    }
    else {
        return a.head < b.head;
    }
}

vector<string> solution(vector<string> files)
{
    vector<string> answer(files.size());
    vector<File> f;

    for (int iter = 0; iter < files.size(); iter++)
        f.push_back(File(files[iter], iter));

    stable_sort(f.begin(), f.end(), Cmp);

    for (int iter = 0; iter < files.size(); iter++)
        answer[iter] = files[f[iter].idx];

    return answer;
}