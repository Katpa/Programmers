string encryption(string s)
{
    string output = "";
    float length = s.size();
    int ySize = sqrt(length);
    int xSize = ceil(sqrt(length));

    if (xSize * ySize < length) ySize++;

    for (int i = 0; i < xSize; i++)
    {
        for (int j = 0; j < ySize; j++)
        {
            int index = i + j * xSize;

            if (index >= length) break;
            output += s[index];
        }

        output += " ";
    }

    return output;
}