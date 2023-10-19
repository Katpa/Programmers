int nonDivisibleSubset(int k, vector<int> arr)
{
    int output = 0;

    if (!(k & 1))
        output += min(arr[k / 2], 1);

    output += min(arr[0], 1);

    for (int i = 1; i <= (k >> 1); i++)
    {
        if (i != k - i)
            output += max(arr[i], arr[k - i]);
    }

    return output;
}