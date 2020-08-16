#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, sum = 0;
    for(int i = 1; i <= n / 2; i++) {
        for(int j = i; j <= n / 2 + 1; j++) {
            sum += j;
            if(sum == n) answer++;
            if(sum > n) break;
        }
        sum = 0;
    }
    return answer;
}
