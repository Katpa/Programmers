#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order)
{
    int index = 0;
    stack<int> subBelt;
    stack<int> mainBelt;

    for (int i = order.size(); i > 0; i--)
        mainBelt.push(i);

    while (true)
    {
        if (!mainBelt.empty() && order[index] == mainBelt.top())
        {
            mainBelt.pop();
            index++;
        }
        else if (!subBelt.empty() && order[index] == subBelt.top())
        {
            subBelt.pop();
            index++;
        }
        else if (mainBelt.empty())
        {
            mainBelt.push(subBelt.top());
            subBelt.pop();
        }
        else
        {
            subBelt.push(mainBelt.top());
            mainBelt.pop();

            if (order[index] != subBelt.top() && mainBelt.empty())
                break;
        }

        if (index == order.size())
            break;
    }

    return index;
}

int main()
{
    vector<int> order = { 4, 3, 1, 2, 5 };

    int answer = solution(order);

    return EXIT_SUCCESS;
}