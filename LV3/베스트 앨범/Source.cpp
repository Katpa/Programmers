#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Song
{
    int playCnt;
    int index;

    Song(int p, int i)
        :playCnt(p), index(i)
    {}
};

struct Genre
{
    string genre;
    int totalPlay;

    Genre(string g, int tp)
        :genre(g), totalPlay(tp)
    {}
};

struct Cmp
{
    bool operator()(const Song& a, const Song& b)
    {
        if (a.playCnt == b.playCnt)
            return a.index > b.index;                       // 올림차순
        else
            return a.playCnt < b.playCnt;                   // 내림차순
    }

    bool operator()(const Genre& a, const Genre& b)
    {
        return a.totalPlay < b.totalPlay;
    }
};

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    map<string, int> totals;
    map<string, priority_queue<Song, vector<Song>, Cmp>> songs;
    priority_queue<Genre, vector<Genre>, Cmp> genre;

    for (int iter = 0; iter < genres.size(); iter++)
    {
        string genre = genres[iter];
        int play = plays[iter];

        totals[genre] += play;
        songs[genre].push(Song(play, iter));
    }

    for (pair<string, int> p : totals)
        genre.push(Genre(p.first, p.second));

    while (!genre.empty())
    {
        int cnt = 0;
        Genre g = genre.top();
        genre.pop();
        while (!songs[g.genre].empty() && cnt < 2)
        {
            answer.push_back(songs[g.genre].top().index);
            songs[g.genre].pop();
            cnt++;
        }
    }

    return answer;
}