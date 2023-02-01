#include <string>
#include <vector>

using namespace std;

vector<long long> f;

void Func(vector<int>& vec, vector<int>& answer, long long& k)
{
    if (vec.size() == 1) {
        answer.push_back(vec[0]);
        return;
    }

    long long p = f[vec.size() - 1];
    for (int i = 1; i <= vec.size(); ++i) {
        if (i * p >= k) {
            answer.push_back(vec[i - 1]);
            vec.erase(vec.begin() + i - 1);
            k = k - (i - 1) * p;
            Func(vec, answer, k);
        }
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> vec;

    f.resize(n);

    f[0] = 1;
    vec.push_back(1);
    for (int i = 1; i < n; i++)
    {
        f[i] = i * f[i - 1];
        vec.push_back(i + 1);
    }

    Func(vec, answer, k);

    return answer;
}

int main()
{
    int n = 3;
    int k = 5;

    vector<int> answer = solution(n, k);

    return EXIT_SUCCESS;
}