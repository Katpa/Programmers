int lilysHomework(vector<int> arr)
{
    int output[2] = {};
    vector<int> arrays[2] = { arr, arr };
    map<int, int> m[2];
    //priority_queue<Part, vector<Part>, Cmp> pq;

    for (int iter = 0; iter < arr.size(); iter++)
    {
        m[0][arr[iter]] = iter;
        m[1][arr[iter]] = iter;
        //pq.push(Part(arr[iter], iter));
    }

    int index = 0;
    for (pair<int, int> p : m[0])
    {
        if (p.first != arrays[0][index])
        {
            int tmp = arrays[0][index];

            arrays[0][index] = p.first;
            m[0][tmp] = p.second;
            m[0][p.first] = index;
            arrays[0][m[0][tmp]] = tmp;

            output[0]++;
        }

        index++;
    }

    index = 0;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arrays[0][i] != arrays[1][index])
        {
            int tmp = arrays[1][index];

            arrays[1][index] = arrays[0][i];
            m[1][tmp] = m[1][arrays[0][i]];
            m[1][arrays[0][i]] = index;
            arrays[1][m[1][tmp]] = tmp;

            output[1]++;
        }

        index++;
    }

    return min(output[0], output[1]);
}