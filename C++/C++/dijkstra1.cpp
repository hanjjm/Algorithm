#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef struct {
    int x, y, dir, cost;
} Car;

int visited[27][27] = {0, };
int dx[4] = {1, 0, -1, 0}; // 위, 오른쪽, 아래, 왼쪽
int dy[4] = {0, 1, 0, -1};

bool check(int x, int y, int len) {
    if(x < 0 || x >= len || y < 0 || y >= len) return false;
    else return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    queue<Car> q;
    
    if(board[0][1] == 0) {
        q.push({0, 1, 0, 100}); // 좌우
        visited[0][1] = 100;
    }
    
    if(board[1][0] == 0) {
        q.push({1, 0, 1, 100}); // 위아래
        visited[1][0] = 100;
    }
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cost = q.front().cost;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nCost = 0;
            if(check(x + dx[i], y + dy[i], board.size())
               && board[x + dx[i]][y + dy[i]] == 0) {
                if(i % 2 == 0) { // 상하
                    if(dir == 0)  nCost += 600;
                    else nCost += 100;
                } else if(i % 2 != 0) { // 좌우
                    if(dir == 0) nCost += 100;
                    else nCost += 600;
                }
            }
            
            if(check(x + dx[i], y + dy[i], board.size())
               && board[x + dx[i]][y + dy[i]] == 0) {
                if(visited[x + dx[i]][y + dy[i]] == 0
                   || visited[x + dx[i]][y + dy[i]] >= nCost + cost) {
                    visited[x + dx[i]][y + dy[i]] = nCost + cost;
                    if(i % 2 == 0) q.push({x + dx[i], y + dy[i], 1, nCost + cost});
                    else q.push({x + dx[i], y + dy[i], 0, nCost + cost});
                }
            }
            
        }
        
    }
    
    return visited[board.size() - 1][board.size() - 1];
}
