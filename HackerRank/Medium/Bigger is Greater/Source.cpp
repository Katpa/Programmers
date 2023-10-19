string biggerIsGreater(string w)
{
    if (w.size() == 1) return "no answer";

    // 뒤에서 수를 검사하는데
    // 내림차순이면 여태 지나온 수 중에서 보다 크되 제일 작은 수를 넣는다.
    // 그 후 남은 수들을 작은 것부터 배치한다.
    // 오름차순이면 통과
    // 만약 끝에 도달하면 가장 마지막 수(0번쨰 수)를 보다 큰 수로 교체한다.
    // 그 후 나머지 수는 작은 것부터 배치한다.
    // 만약 보다 큰 수가 없으면 no answer

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