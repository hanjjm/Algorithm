//
//  p13460.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/27.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int row, column;
pair<int, int> hole;
char board[10][10];
int dx[4] = {1, 0, -1, 0}; // 하, 우, 상, 좌
int dy[4] = {0, 1, 0, -1};
int answer = 999;

void printBoard() {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) cout << board[i][j];
        cout << endl;
    }
    cout << endl;
}

void solve(int count, pair<int, int> red, pair<int, int> blue, int dir) {
    if(count == 10) return;
    bool redFinish = false, blueFinish = false, flag = false;;
    
    char copyBoard[10][10];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) copyBoard[i][j] = board[i][j];
    }
    
    while(true) {
        if(board[red.first + dx[dir]][red.second + dy[dir]] == 'B' && !flag) { // red부터 시작하는데, 만약 다음이 Blue면
            while(true) { // Blue 먼저 옮겨줌.
                if(board[blue.first + dx[dir]][blue.second + dy[dir]] == '.') {
                    board[blue.first + dx[dir]][blue.second + dy[dir]] = 'B';
                    board[blue.first][blue.second] = '.'; // 교환.
                    blue.first += dx[dir];
                    blue.second += dy[dir];
                } else if(board[blue.first + dx[dir]][blue.second + dy[dir]] == 'O') {
                    blueFinish = true;
                    board[blue.first][blue.second] = '.';
                    flag = true;
                    break;
                } else {
                    flag = true;
                    break;
                }
            }
        } else if(board[red.first + dx[dir]][red.second + dy[dir]] == '.') {
            board[red.first + dx[dir]][red.second + dy[dir]] = 'R';
            board[red.first][red.second] = '.'; // 교환.
            red.first += dx[dir];
            red.second += dy[dir];
        } else if(board[red.first + dx[dir]][red.second + dy[dir]] == 'O') {
            redFinish = true;
            board[red.first][red.second] = '.';
            break;
        } else break;
    }
    
    while(true) {
        if(board[blue.first + dx[dir]][blue.second + dy[dir]] == '.') {
            board[blue.first + dx[dir]][blue.second + dy[dir]] = 'B';
            board[blue.first][blue.second] = '.'; // 교환.
            blue.first += dx[dir];
            blue.second += dy[dir];
        } else if(board[blue.first + dx[dir]][blue.second + dy[dir]] == 'O') {
            blueFinish = true;
            board[blue.first][blue.second] = '.';
            break;
        } else break;
    }
    
    if(blueFinish) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) board[i][j] = copyBoard[i][j]; // 배열 다시 초기화.
        }
        return;
    }
    if(redFinish) {
        answer = min(answer, count);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) board[i][j] = copyBoard[i][j]; // 배열 다시 초기화.
        }
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(i != dir) solve(count + 1, red, blue, i);
    }
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) board[i][j] = copyBoard[i][j]; // 배열 다시 초기화.
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    pair<int, int> red, blue;
    
    cin >> row >> column;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') red = make_pair(i, j);
            if(board[i][j] == 'B') blue = make_pair(i, j);
            if(board[i][j] == 'O') hole = make_pair(i, j);
        }
    }
    
    char copyBoard[10][10];
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) copyBoard[i][j] = board[i][j];
    }
    
    for(int i = 0; i < 4; i++) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) board[i][j] = copyBoard[i][j]; // 배열 다시 초기화.
        }
        solve(0, red, blue, i);
    }
    
    if(answer + 1 > 10) cout << -1 << endl;
    else cout << answer + 1 << endl;
}
