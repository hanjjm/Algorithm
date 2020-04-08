#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int length = triangle.size();
    int DP[length][length];
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) DP[i][j] = 0;
    }
    DP[0][0] = triangle[0][0];
    DP[1][0] = triangle[0][0] + triangle[1][0];
    DP[1][1] = triangle[0][0] + triangle[1][1];
    for(int i = 2; i < length; i++) {
        for(int j = 0; j < i + 1; j++) {
            if(j == 0) DP[i][j] = DP[i - 1][j] + triangle[i][0];
            else if(j == i) DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            else DP[i][j] = triangle[i][j] + max(DP[i - 1][j - 1], DP[i - 1][j]);
        }
    }
    for(int i = 0; i < length; i++) {
        answer = max(answer, DP[length - 1][i]);
    }
    return answer;
}
