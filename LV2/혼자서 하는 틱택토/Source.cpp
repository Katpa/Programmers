#include <string>
#include <vector>

using namespace std;

bool IsWin(vector<string> board, char player)
{
    for (int iter = 0; iter < 3; iter++)
    {
        // 가로
        if (board[0][iter] == player && board[0][iter] == board[1][iter] && board[1][iter] == board[2][iter]) return true;
        // 세로
        if (board[iter][0] == player && board[iter][0] == board[iter][1] && board[iter][1] == board[iter][2]) return true;
    }
    // 대각선
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[2][0] == player && board[2][0] == board[1][1] && board[1][1] == board[0][2]) return true;

    return false;
}

int solution(vector<string> board)
{
    // o와 x의 개수 카운팅
    int Xcnt = 0, Ocnt = 0;
    for (string str : board)
    {
        for (char c : str)
        {
            if (c == 'O')
                Ocnt++;
            else if (c == 'X')
                Xcnt++;
        }
    }

    int OmX = Ocnt - Xcnt;

    bool Owin = IsWin(board, 'O');
    bool Xwin = IsWin(board, 'X');

    if (OmX > 1 || OmX < 0) return 0;           // 턴 수가 맞지 않는 경우
    if (Owin > 0 && OmX != 1) return 0;         // O가 승리했지만 마지막에 O가 두지 않은 경우
    if (Xwin > 0 && OmX != 0) return 0;         // X가 승리했지만 마지막에 X가 두지 않은 경우
    if (Owin && Xwin) return 0;                 // O, X 모두가 유효한 줄을 가지고 있는 경우 (=둘다 승리한 경우)

    return 1;
}