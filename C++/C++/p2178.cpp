//
//  p2178.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/04.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int matrix[102][102] = {0, };
int visited[102][102] = {0, };
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0} , {0, -1}};

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void input(int N, int M) {
    for(int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        for(int j = 1; j <= M; j++) matrix[i][j] = temp[j - 1] - '0';
    }
}

int dfs(int N, int M, int x, int y) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    
    while(!q.empty()) {
        pair<int, int> fro = q.front();
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            if(visited[fro.first + direction[i][0]][fro.second + direction[i][1]] == 0
               && matrix[fro.first + direction[i][0]][fro.second + direction[i][1]] == 1) {
                visited[fro.first + direction[i][0]][fro.second + direction[i][1]] = visited[fro.first][fro.second] + 1;
                q.push(make_pair(fro.first + direction[i][0], fro.second + direction[i][1]));
            }
        }
    }
    return visited[N][M];
}

int main() {
    int N, M;
    cin >> N >> M;
    init();
    input(N, M);
    int answer = dfs(N, M, 1, 1);
    cout << answer;
}
