void Rotate(vector<int>& a, int start, int num)
{
    while (a[start] != num)
    {
        int tmp = a[start];
        a[start] = a[start + 1];
        a[start + 1] = a[start + 2];
        a[start + 2] = tmp;
    }
}

string larrysArray(vector<int> A)
{
    int size = A.size();
    vector<bool> correct(size, false);
    for (int i = 0; i < size - 2; i++)
    {
        if (A[i] == i + 1)
        {
            correct[i] = true;
            continue;
        }

        for (int j = i; j < size; j++)
        {
            if (A[j] != i + 1) continue;

            if (j - 2 > 0 && correct[j - 2] == false)
                Rotate(A, j - 2, i + 1);
            else
                Rotate(A, j - 1, i + 1);
        }

        if (A[i] != i + 1) i--;
        else correct[i] = true;
    }

    if (A[size - 2] != size - 1) return "NO";
    if (A[size - 1] != size) return "NO";

    return "YES";
}