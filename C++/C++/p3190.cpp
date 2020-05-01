//
//  p3190.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/30.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int matrix[102][102];
int second[100];
char direction[100];

void init() { // matrix 초기화
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) matrix[i][j] = 0;
    }
}

void appleInit(int apple) { //사과 초기화
    for(int i = 0; i < apple; i++) {
        int x, y;
        cin >> x >> y;
        matrix[x][y] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    int N, L, apple;
    cin >> N >> apple;
    appleInit(apple);
    cin >> L;
    for(int i = 0; i < L; i++) cin >> second[i] >> direction[i];
    int time = 1, index = 0;
    char dir = 'R';
    deque<pair<int, int>> deq;
    deq.push_back(make_pair(1, 1));
    while(true) {
        int flag = 0;
        if(time == second[index]) {
            if(direction[index] == 'L') {
                if(dir == 'R') dir = 'U';
                else if(dir == 'L') dir = 'D';
                else if(dir == 'U') dir = 'L';
                else if(dir == 'D') dir = 'R';
            } else {
                if(dir == 'R') dir = 'D';
                else if(dir == 'L') dir = 'U';
                else if(dir == 'U') dir = 'R';
                else if(dir == 'D') dir = 'L';
            }
            index++;
        }
        if(dir == 'R') {
            if(deq.front().second + 1 == N + 1) break;
            for(int i = 0; i < deq.size(); i++) {
                if(deq.front().first == deq[i].first && deq.front().second + 1 == deq[i].second) flag = 1;
            }
            if(flag) break;
            if(!matrix[deq.front().first][deq.front().second + 1]) {
                deq.push_front(make_pair(deq.front().first, deq.front().second + 1));
                deq.pop_back();
            } else {
                matrix[deq.front().first][deq.front().second + 1] = 0;
                deq.push_front(make_pair(deq.front().first, deq.front().second + 1));
            }
        } else if(dir == 'L') {
            if(deq.front().second - 1 == -1) break;
            for(int i = 0; i < deq.size(); i++) {
                if(deq.front().first == deq[i].first && deq.front().second - 1 == deq[i].second) flag = 1;
            }
            if(flag) break;
            if(!matrix[deq.front().first][deq.front().second - 1]) {
                deq.push_front(make_pair(deq.front().first, deq.front().second - 1));
                deq.pop_back();
            } else {
                matrix[deq.front().first][deq.front().second - 1] = 0;
                deq.push_front(make_pair(deq.front().first, deq.front().second - 1));
            }
        } else if(dir == 'U') {
            if(deq.front().first - 1 == -1) break;
            for(int i = 0; i < deq.size(); i++) {
                if(deq.front().first - 1 == deq[i].first && deq.front().second == deq[i].second) flag = 1;
            }
            if(flag) break;
            if(!matrix[deq.front().first - 1][deq.front().second]) {
                deq.push_front(make_pair(deq.front().first - 1, deq.front().second));
                deq.pop_back();
            } else {
                matrix[deq.front().first - 1][deq.front().second] = 0;
                deq.push_front(make_pair(deq.front().first - 1, deq.front().second));
            }
        } else if(dir == 'D') {
            if(deq.front().first + 1 == N + 1) break;
            for(int i = 0; i < deq.size(); i++) {
                if(deq.front().first + 1 == deq[i].first && deq.front().second == deq[i].second) flag = 1;
            }
            if(flag) break;
            if(!matrix[deq.front().first + 1][deq.front().second]) {
                deq.push_front(make_pair(deq.front().first + 1, deq.front().second));
                deq.pop_back();
            } else {
                matrix[deq.front().first + 1][deq.front().second] = 0;
                deq.push_front(make_pair(deq.front().first + 1, deq.front().second));
            }
                
        }
        time++;
    }
    cout << time + 1;
}
