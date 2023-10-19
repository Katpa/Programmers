string biggerIsGreater(string w)
{
    if (w.size() == 1) return "no answer";

    // �ڿ��� ���� �˻��ϴµ�
    // ���������̸� ���� ������ �� �߿��� ���� ũ�� ���� ���� ���� �ִ´�.
    // �� �� ���� ������ ���� �ͺ��� ��ġ�Ѵ�.
    // ���������̸� ���
    // ���� ���� �����ϸ� ���� ������ ��(0���� ��)�� ���� ū ���� ��ü�Ѵ�.
    // �� �� ������ ���� ���� �ͺ��� ��ġ�Ѵ�.
    // ���� ���� ū ���� ������ no answer

    map<char, int> m;
    m[w[w.size() - 1]]++;
    bool isFound = false;

    for (int i = w.size() - 2; i >= 0; i--)
    {
        m[w[i]]++;
        if (w[i] >= w[i + 1]) continue;

        for (pair<char, int> p : m)
        {
            if (p.first <= w[i]) continue;

            m[p.first]--;
            w[i] = p.first;

            for (int j = i + 1; j < w.size(); j++)
            {
                for (pair<char, int> p2 : m)
                {
                    if (p2.second == 0) continue;
                    w[j] = p2.first;
                    m[p2.first]--;
                    break;
                }
            }
            break;
        }
        isFound = true;
        break;
    }

    if (isFound) return w;

    for (pair<char, int> p : m)
    {
        if (p.first <= w[0]) continue;

        isFound = true;
        w[0] = p.first;
        m[p.first]--;

        for (int j = 1; j < w.size(); j++)
        {
            for (pair<char, int> p2 : m)
            {
                if (p2.second == 0) continue;
                w[j] = p2.first;
                m[p2.first]--;
                break;
            }
        }
        break;
    }

    if (isFound) return w;

    return "no answer";
}