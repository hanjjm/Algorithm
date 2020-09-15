//
//  p1175.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
char arr[52][52];
int visited[52][52][4] = {0, }; // 4방향
int dx[4] = {0, 1, 0, -1}; // 우, 하, 좌, 상
int dy[4] = {1, 0, -1, 0};
int row, column, answer = 987654321;

typedef struct {
    int x, y, dir, time, gift;
} Minsik;

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> row >> column;
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            arr[i][j] = '0';
            for(int k = 0; k < 4; k++) visited[i][j][k] = 1; // 편의상 일단 전부 1로 초기화
        }
    }
}

queue<Minsik> now;
void input() {
    for(int i = 1; i <= row; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= column; j++) {
            arr[i][j] = temp[j - 1];
            
            if(temp[j - 1] == 'S') { // 시작 포인트
                for(int k = 0; k < 4; k++) {
                    now.push({i, j, k, 0, 0});
                    visited[i][j][k] = 1; // 시작 지점의 4방향 방문완료.
                }
            }
            
            if(temp[j - 1] == 'C' || temp[j - 1] == '.') { // 민식이가 방문할 수 있는 곳
                for(int k = 0; k < 4; k++) visited[i][j][k] = 0;
            }
        }
    }
}

void initVisited(int x, int y) { // 첫 번째 선물을 방문하면 다시 bfs를 위해 초기화
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            for(int k = 0; k < 4; k++) visited[i][j][k] = 1;
        }
    }
    
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            if(arr[i][j] == 'C' || arr[i][j] == '.' || arr[i][j] == 'S') {
                for(int k = 0; k < 4; k++) visited[i][j][k] = 0;
            }
        }
    }
}

void printArr() {
    cout << endl;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) cout << arr[i][j];
        cout << endl;
    }
    cout << endl;
}

void solve() {
    while(!now.empty()) {
        int x = now.front().x;
        int y = now.front().y;
        int dir = now.front().dir;
        int time = now.front().time;
        int gift = now.front().gift;
        now.pop();
//        cout << x << " " << y << " " << dir << " " << time << " " << gift << endl;
        bool flag = false;
        for(int i = 0; i < 4; i++) {
            if(dir != i && visited[x + dx[i]][y + dy[i]][i] == 0) {
                visited[x + dx[i]][y + dy[i]][i] = 1;
                
                if(arr[x + dx[i]][y + dy[i]] == 'C') { //선물 발견.
//                    printArr();
                    if(gift == 0) { // 첫번째 선물이면
                        initVisited(x + dx[i], y + dy[i]);
                        
                        queue<Minsik> temp;
                        while(!now.empty()) {
                            for(int j = 0; j < 4; j++) {
                                if(i != j && now.front().x + dx[j] == x + dx[i]
                                   && now.front().y + dy[j] == y + dy[i]) {
                                    temp.push({x + dx[i], y + dy[i], j, time + 1, gift + 1});
                                    visited[x + dx[i]][y + dy[i]][j] = 1;
                                }
                            }
                            now.pop();
                        }
                        
                        while(!temp.empty()) {
                            now.push(temp.front());
                            temp.pop();
                        }
                        
                        now.push({x + dx[i], y + dy[i], i, time + 1, gift + 1}); // 현재 위치에서 다시 시작
                        visited[x + dx[i]][y + dy[i]][i] = 1;
                        arr[x + dx[i]][y + dy[i]] = '.';
                        break;
                    } else if(gift == 1) { // 두 번째 선물이면
                        flag = true;
                        answer = time + 1;
                        break;
                    }
                }
                
                now.push({x + dx[i], y + dy[i], i, time + 1, gift});
            }
        }
        
        if(flag) break;
    }
}

int main() {
    init();
    input();
    solve();
    
    if(answer == 987654321) cout << -1;
    else cout << answer;
    
    return 0;
}
