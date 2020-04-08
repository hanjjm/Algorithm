#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long DP[N][2];
    DP[0][0] = 1; DP[0][1] = 1;
    DP[1][0] = 2; DP[1][1] = 1;
    for(int i = 2; i < N; i++) {
        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]);
        DP[i][1] = DP[i][0] + min(DP[i - 1][0], DP[i - 1][1]);
    }
    answer = 2 * (DP[N - 1][0] + DP[N - 1][1]);
    return answer;
}
