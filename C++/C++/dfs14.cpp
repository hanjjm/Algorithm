#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int check[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    vector<pair<int, int>> vec;
    set<char> s;
    while(true) {
        
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(board[i][j] == 0) continue;
                for(int k = 0; k < 4; k++) {
                    s.insert(board[i + check[k][0]][j + check[k][1]]);
                }
                if(s.size() == 1) { // 다 같은 판일 때 체크
                    for(int k = 0; k < 4; k++) {
                        vec.push_back(make_pair(i + check[k][0], j + check[k][1]));
                    }
                }
                s.clear();
            }
        }
        
        if(vec.empty()) break;
        int vecSize = vec.size();
        for(int k = 0; k < vecSize; k++) { // 삭제
            if(board[vec[k].first][vec[k].second] != 0) {
                board[vec[k].first][vec[k].second] = 0;
                answer++;
            }
        }
        vec.clear();
        
        for(int i = m - 1; i > 0; i--) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] != 0) continue;
                int index = 1;
                while(true) {
                    if(i - index <= 0 || board[i - index][j] != 0) break;
                    index++;
                }
                char temp = board[i][j];
                board[i][j] = board[i - index][j];
                board[i - index][j] = temp;
            }
        }
        
    }
    return answer;
}
