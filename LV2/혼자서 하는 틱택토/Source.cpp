#include <string>
#include <vector>

using namespace std;

bool IsWin(vector<string> board, char player)
{
    for (int iter = 0; iter < 3; iter++)
    {
        // ����
        if (board[0][iter] == player && board[0][iter] == board[1][iter] && board[1][iter] == board[2][iter]) return true;
        // ����
        if (board[iter][0] == player && board[iter][0] == board[iter][1] && board[iter][1] == board[iter][2]) return true;
    }
    // �밢��
    if (board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[2][0] == player && board[2][0] == board[1][1] && board[1][1] == board[0][2]) return true;

    return false;
}

int solution(vector<string> board)
{
    // o�� x�� ���� ī����
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

    if (OmX > 1 || OmX < 0) return 0;           // �� ���� ���� �ʴ� ���
    if (Owin > 0 && OmX != 1) return 0;         // O�� �¸������� �������� O�� ���� ���� ���
    if (Xwin > 0 && OmX != 0) return 0;         // X�� �¸������� �������� X�� ���� ���� ���
    if (Owin && Xwin) return 0;                 // O, X ��ΰ� ��ȿ�� ���� ������ �ִ� ��� (=�Ѵ� �¸��� ���)

    return 1;
}