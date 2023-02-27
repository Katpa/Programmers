#include <string>
#include <vector>
#include <queue>

using namespace std;

#define HOUR 60

struct Book
{
public:
    Book(string in, string out)
        :checkIn(ToTime(in)), checkOut(ToTime(out))
    {
        checkOut += 10;
    }

private:
    int ToTime(string str)
    {
        string hour(str.begin(), str.begin() + 2);
        string minute(str.begin() + 3, str.begin() + 5);
        return stoi(hour) * HOUR + stoi(minute);
    }

public:
    int checkIn;
    int checkOut;
};

struct compare {
    bool operator()(const Book& m1, const Book& m2) { return m1.checkIn > m2.checkIn; }
};

int solution(vector<vector<string>> book_time)
{
    priority_queue<Book, vector<Book>, compare> pq;
    vector<int> rooms;

    for (vector<string> vec : book_time)
        pq.push(Book(vec[0], vec[1]));

    while (!pq.empty())
    {
        Book curBook = pq.top();
        pq.pop();

        bool checked = false;

        for (int& checkOutTime : rooms)
        {
            if (checkOutTime > curBook.checkIn) continue;
            checkOutTime = curBook.checkOut;
            checked = true;
            break;
        }

        if (!checked)
            rooms.push_back(curBook.checkOut);
    }

    return rooms.size();
}

int main()
{
    vector<vector<string>> book_time = { {"15:00", "17:00"}, {"16:40", "18:20"},{"14:20", "15:20"},{"14:10", "19:20"},{"18:20", "21:20"} };

    int answer = solution(book_time);

    return EXIT_SUCCESS;
}