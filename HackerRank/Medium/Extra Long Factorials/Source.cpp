void extraLongFactorials(int n)
{
    int arr[300] = { 1, };
    int size = 1;

    for (int i = 1; i < 300; i++)
        arr[i] = -1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < size; j++)
            arr[j] *= i;

        for (int j = 0; j < 300; j++)
        {
            if (arr[j] == -1)
            {
                size = j;
                break;
            }

            if (arr[j] >= 10)
            {
                if (arr[j + 1] == -1)
                    arr[j + 1] = arr[j] / 10;
                else
                    arr[j + 1] += arr[j] / 10;

                arr[j] %= 10;
            }
        }
    }

    for (int i = size - 1; i >= 0; i--)
        cout << arr[i];
}