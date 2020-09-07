#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int match[101][101] = {0, };
    
    for(int i = 0; i < results.size(); i++) {
        int winner = results[i][0];
        int loser = results[i][1];
        match[winner][loser] = 1;
        match[loser][winner] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(match[j][i] == 1) {
                for(int k = 1; k <= n; k++) {
                    if(match[i][k] == 1) match[j][k] = 1;
                }
            }
            
            if(match[j][i] == -1) {
                for(int k = 1; k <= n; k++) {
                    if(match[i][k] == -1) match[j][k] = -1;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        bool flag = false;
        for(int j = 1; j <= n; j++) {
            if(i != j && match[i][j] == 0) flag = true;
            if(flag) break;
        }
        if(flag) continue;
        answer++;
    }
    
    return answer;
}
