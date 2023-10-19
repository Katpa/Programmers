void SayYes() { cout << "yes" << endl; }

void almostSorted(vector<int> arr)
{
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    int size = arr.size();
    vector<int> diffIndices;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == sorted[i]) continue;

        diffIndices.push_back(i);
    }

    if (diffIndices.size() == 0)
        SayYes();
    else if (diffIndices.size() == 2)
    {
        SayYes();
        cout << "swap " << diffIndices[0] + 1 << " " << diffIndices[1] + 1;
    }
    else
    {
        int start = diffIndices[0];
        int end = diffIndices[diffIndices.size() - 1];

        while (start < end)
        {
            swap(arr[start], arr[end]);
            start++; end--;
        }

        for (int i = 0; i < size; i++)
        {
            if (arr[i] != sorted[i])
            {
                cout << "no" << endl;
                return;
            }
        }

        SayYes();
        cout << "reverse " << diffIndices[0] + 1 << " " << diffIndices.back() + 1;
    }
}