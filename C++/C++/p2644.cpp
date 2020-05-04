//
//  p2644.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/04.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> vec(100);
int people, first, second, testCase;
int visited[102] = {0, };

void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void input() {
    cin >> people >> first >> second >> testCase;
    for(int i = 0; i < testCase; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
}

int bfs() {
    queue<int> q;
    q.push(first);
    
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now == second) return visited[now];
        for(int i = 0; i < vec[now].size(); i++) {
            if(visited[vec[now][i]] == 0) {
                q.push(vec[now][i]);
                visited[vec[now][i]] = visited[now] + 1;
            }
        }
    }
    
    return -1;
}

int main() {
    init();
    input();
    int answer = bfs();
    cout << answer;
}
