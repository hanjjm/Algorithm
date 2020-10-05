//
//  p19237.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/06.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

typedef struct {
    int x, y, dir;
    bool alive;
} Shark;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int len, sharkNum, smell;
    pair<int, int> board[22][22];
    Shark shark[401];
    
    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < 22; j++) {
            board[i][j].first = -1;
            board[i][j].second = -1;
        }
    }
    
    cin >> len >> sharkNum >> smell;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            cin >> board[i][j].first;
            if(board[i][j].first == 0) board[i][j].second = 0; // 상어가 없으면
            else {
                board[i][j].second = smell; // 상어가 있으면
                shark[board[i][j].first].alive = true;
                shark[board[i][j].first].x = i;
                shark[board[i][j].first].y = j;
            }
        }
    }
    
    for(int i = 1; i <= sharkNum; i++) cin >> shark[i].dir;
    // 위, 아래, 좌, 우 = 1, 2, 3, 4
    int priority[401][5][5];
    for(int i = 1; i <= sharkNum; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 1; k <= 4; k++) cin >> priority[i][j][k];
        }
    }
    
    int timer = 1;
    int dx[5] = {0, -1, 1, 0, 0};
    int dy[5] = {0, 0, 0, -1, 1};
    
    while(timer != 1001) {
        for(int i = 1; i <= sharkNum; i++) { // 상어 이동.
            if(shark[i].alive == false) continue; // 죽은 상어는 넘긴다.
            
            bool flag = false;
            for(int j = 1; j <= 4; j++) { // 인접한 칸중에 빈곳
                if(board[shark[i].x + dx[priority[i][shark[i].dir][j]]][shark[i].y + dy[priority[i][shark[i].dir][j]]].second == 0) {
                    shark[i].x += dx[priority[i][shark[i].dir][j]];
                    shark[i].y += dy[priority[i][shark[i].dir][j]];
                    shark[i].dir = priority[i][shark[i].dir][j];
                    flag = true;
                    break;
                }
            }
            
            if(flag) continue;
            for(int j = 1; j <= 4; j++) { // 인접한 칸중에 자기 냄새 있는 곳
                if(board[shark[i].x + dx[priority[i][shark[i].dir][j]]][shark[i].y + dy[priority[i][shark[i].dir][j]]].first == i) {
                    shark[i].x += dx[priority[i][shark[i].dir][j]];
                    shark[i].y += dy[priority[i][shark[i].dir][j]];
                    shark[i].dir = priority[i][shark[i].dir][j];
                    break;
                }
            }
            
        }
        
        for(int i = 1; i <= len; i++) {
            for(int j = 1; j <= len; j++) {
                if(board[i][j].second != 0 && board[i][j].second != -1) {
                    board[i][j].second--;
                    if(board[i][j].second == 0) board[i][j].first = 0;
                }
            }
        }
        
        for(int i = 1; i <= sharkNum; i++) { // 겹치면 죽인다.
            if(shark[i].alive == false) continue; // 죽은 상어는 넘긴다.
            
            bool flag = false;
            for(int j = 1; j < i; j++) { // 자기보다 순위 높은 상어랑 겹치면, 나는 죽음.
                if(shark[j].alive && shark[i].x == shark[j].x && shark[i].y == shark[j].y) {
                    shark[i].alive = false;
                    if(i == 1) cout << "@";
                    flag = true;
                    break;
                }
            }
            
            if(flag) continue;
            board[shark[i].x][shark[i].y].first = i;
            board[shark[i].x][shark[i].y].second = smell;
        }
        
        bool flag = true;
        for(int i = 2; i <= sharkNum; i++) {
            if(shark[i].alive == true) flag = false;
        }
        
        if(flag) break;
        timer++;
    }
    
    if(timer == 1001) cout << -1 << endl;
    else cout << timer << endl;
}
