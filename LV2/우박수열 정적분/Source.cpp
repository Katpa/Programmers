#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> collatz(200, k);
    int maxSize = 1;

    while (k > 1 && maxSize < 200)
    {
        if (k & 1)
            k = k * 3 + 1;
        else
            k >>= 1;

        collatz[maxSize] = k;
        maxSize++;
    }
    maxSize--;

    for (int acNum = 0; acNum < ranges.size(); acNum++)
    {
        int start = ranges[acNum][0], end = maxSize + ranges[acNum][1];
        double area = 0.0f;
        for (int iter = start; iter < end; iter++)
            area += (collatz[iter] + collatz[iter + 1]) * 0.5f;

        if (start > end) area = -1.0f;
        answer.push_back(area);
    }

    return answer;
}