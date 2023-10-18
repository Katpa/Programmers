int surfaceArea(vector<vector<int>> A)
{
    int h = A.size(), w = A[0].size();

    vector<int> H(h, 0);
    vector<int> W(w, 0);

    for (int i = 0; i < h; i++)
    {
        int lastNum = 0;

        for (int value : A[i])
        {
            if (lastNum < value)
                H[i] += value - lastNum;

            lastNum = value;
        }
    }

    for (int i = 0; i < w; i++)
    {
        int lastNum = 0;
        for (int j = 0; j < h; j++)
        {
            if (lastNum < A[j][i])
                W[i] += A[j][i] - lastNum;

            lastNum = A[j][i];
        }
    }

    int sumH = 0, sumW = 0;

    for (int iter = 0; iter < h; iter++)
        sumH += H[iter];

    for (int iter = 0; iter < w; iter++)
        sumW += W[iter];

    int output = (h * w * 2) + (sumH + sumW) * 2;

    return output;
}