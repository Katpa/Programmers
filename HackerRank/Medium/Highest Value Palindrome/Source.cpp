string highestValuePalindrome(string s, int n, int k)
{
    int start = 0, end = n - 1;
    int diff = 0;

    for (int i = 0, j = n - 1; i < (n >> 1); i++, j--)
    {
        if (s[i] != s[j])
            diff++;
    }

    if (diff > k) return "-1";

    while (start <= end)
    {
        if (k <= 0) break;

        if (s[start] == s[end])
        {
            if (k > 1 && (k - 2) >= diff && s[start] != '9')
            {
                s[start] = '9';
                s[end] = '9';
                k -= 2;
            }
        }
        else
        {
            if (k > 1 && (k - 2) >= diff - 1)
            {
                if (s[start] != '9')
                {
                    s[start] = '9';
                    k--;
                }

                if (s[end] != '9')
                {
                    s[end] = '9';
                    k--;
                }
            }
            else
            {
                if (s[start] > s[end])
                    s[end] = s[start];
                else
                    s[start] = s[end];

                k--;
            }
            diff--;
        }

        if (start == end && k > 0)
        {
            s[start] = '9';
            k--;
        }
        start++;
        end--;
    }

    if (diff > 0) return "-1";

    return s;
}