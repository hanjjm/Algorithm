#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int len = money.size();
    int DP1[len - 1], DP2[len];
    DP1[0] = money[0]; DP1[1] = money[0];
    DP2[0] = 0; DP2[1] = money[1];
    
    for(int i = 2; i < len - 1; i++) {
        DP1[i] = max(DP1[i - 1], DP1[i - 2] + money[i]); // 처음 집 훔침
    }
    
    for(int i = 2; i < len; i++) {
        DP2[i] = max(DP2[i - 1], DP2[i - 2] + money[i]); // 처음 집 안훔침
    }
    
    return max(DP1[len - 2], DP2[len - 1]);
}
