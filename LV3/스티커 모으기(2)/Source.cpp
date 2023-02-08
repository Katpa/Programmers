#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> sticker)
{
    int answer;
    int length = sticker.size();
    vector<int> dp(sticker.size());

    //검사가 2부터 시작하기 때문에 사이즈가 2일 때까지 체크한다.
    if (sticker.size() == 1) return sticker[0];
    if (sticker.size() == 2) return max(sticker[0], sticker[1]);

    /// 첫번째를 뜯은 경우
    /// 이 경우엔 sticker의 마지막은 검사 범위에서 제외한다.
    /// dp[i] = max(이번 스티커를 뜯지 않은 경우, 이번 스티커를 뜯은 경우);
    dp[0] = sticker[0];
    dp[1] = dp[0];
    for (int i = 2; i < length - 1; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);

    answer = dp[length - 2];

    /// 두번째를 뜯은 경우
    /// 
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < length; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);

    answer = max(answer, dp[length - 1]);

    return answer;
}

int main()
{
    vector<int> sticker = { 14, 6, 5, 11, 3, 9, 2, 10 };

    int answer = solution(sticker);

    return EXIT_SUCCESS;
}