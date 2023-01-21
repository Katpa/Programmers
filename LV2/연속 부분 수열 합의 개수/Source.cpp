#include <vector>
#include <map>

using namespace std;

int solution(vector<int> elements) {
    map<int, int> m;
    int size = elements.size();

    for (int i = 0; i < size; i++)
    {
        // i�� ���� ����
        // j�� ���� �� ���� ��ġ
        // q�� ���� �� ����
        for (int j = 0; j < size; j++)
        {
            int sum = 0;

            for (int q = 0; q < i + 1; q++)
            {
                int tmp = q + j;
                if (tmp >= size)
                    tmp %= size;
                sum += elements[tmp];
            }

            m[sum]++;
        }
    }

    return m.size();
}

int main()
{
    vector<int> elements = { 7,9,1,1,4 };

    int answer = solution(elements);

    return EXIT_SUCCESS;
}