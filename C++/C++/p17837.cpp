//
//  p17837.cpp
//  C++
//
//  Created by KimHanJu on 2020/06/05.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

struct Horse {
    int x, y, direction, number;
};

vector<int> matrix[14][14];
int chess[14][14] = {0, };
int visited[14][14] = {0, };
int len, horseCount;
Horse eachHorse[10];

void input() {
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) cin >> chess[i][j];
    }
    for(int i = 0; i < 10; i++) { // 초기화
        eachHorse[i] = {0, 0, 0, 0};
    }
    for(int i = 0; i < horseCount; i++) {
        int x, y, dir;
        cin >> x >> y >> dir;
        eachHorse[i].x = x;
        eachHorse[i].y = y;
        eachHorse[i].direction = dir;
        eachHorse[i].number = i + 1;
        matrix[x][y].push_back(eachHorse[i].number);
        visited[x][y]++;
    }
}

void move(int i) {
    if(eachHorse[i].direction == 1) { // 오
        if(chess[eachHorse[i].x][eachHorse[i].y + 1] == 2 || eachHorse[i].y + 1 == len) {
            eachHorse[i].direction = 2;
            if(chess[eachHorse[i].x][eachHorse[i].y - 1] == 2 || eachHorse[i].y - 1 == 0) {
                eachHorse[i].direction = 1;
                return;
            } else move(i);
        } else if(chess[eachHorse[i].x][eachHorse[i].y + 1] == 0) {
            int eachSize = visited[eachHorse[i].x][eachHorse[i].y];
            int flag = 0, count = 0, index = 0;
            for(int i = 0; i < eachSize; i++) {
                if(matrix[eachHorse[i].x][eachHorse[i].y][i] == i) {
                    visited[eachHorse[i].x][eachHorse[i].y]--;
                    visited[eachHorse[i].x][eachHorse[i].y + 1]++;
                    count++;
                    index = i;
                    flag = 1;
//                    matrix[eachHorse[i].x][eachHorse[i].y + 1].push_back(0);
                } else if(flag) {
                    visited[eachHorse[i].x][eachHorse[i].y]--;
                    visited[eachHorse[i].x][eachHorse[i].y + 1]++;
                    count++;
                }
            }
        } else if(chess[eachHorse[i].x][eachHorse[i].y + 1] == 1) {
                
        }
    } else if(eachHorse[i].direction == 2) { // 왼
        
    } else if(eachHorse[i].direction == 3) { // 위
        
    } else if(eachHorse[i].direction == 3) { // 아래
        
    }
}

void solve() {
    for(int i = 0; i < horseCount; i++) move(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> len >> horseCount;
    input();
    for(int i = 0; i < 1000; i++) solve();
}
