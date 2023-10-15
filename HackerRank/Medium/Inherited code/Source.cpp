class BadLengthException
{
    int shortNum;
public:
    BadLengthException(int n)
    {
        shortNum = n;
    }
    int what()
    {
        return shortNum;
    }
};
