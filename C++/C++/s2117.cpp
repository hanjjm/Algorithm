//
//  s2117.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/28.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int matrix[22][22];
int visited[22][22];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M, K;

void initMatrix() {
    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < 22; j++) matrix[i][j] = 0;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> matrix[i][j];
    }
}

void initVisited() {
    for(int i = 0; i < 22; i++) {
        for(int j = 0; j < 22; j++) visited[i][j] = 0;
    }
}

void bfs() {
    queue<pair<int, int>> q;
    K = 1;
    
    while(true) {
        int flag = 0;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                q.push(make_pair(i, j));
                int money = 0;
                initVisited();
                visited[i][j] = 1;
                int temp = K;
                while(temp != 0) {
                    int frontX = q.front().first;
                    int frontY = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        if(visited[frontX + dx[k]][frontY + dy[k]] == 0) {
                            q.push(make_pair(frontX + dx[k], frontY + dy[k]));
                            visited[frontX + dx[k]][frontY + dy[k]] = visited[frontX][frontY] + 1;
                            if(matrix[frontX + dx[k]][frontY + dy[k]] == 1) money += M;
                        }
                    }
                    if((K + 1) * (K + 1) + K * K <= money) flag = 1;
                    if(flag) break;
                    temp--;
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(!flag) break;
        K++;
    }1
    cout << K << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        cin >> N >> M;
        initMatrix();
        initVisited();
        bfs();
    }
}
