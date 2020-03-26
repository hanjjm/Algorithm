//
//  p1260.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/25.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> vec(1000);
vector<bool> check(1000);
stack<int> st;
queue<int> q;

void DFS(int startPoint) {
    st.push(startPoint);
    
    while(!st.empty()) {
        int stTop = st.top();
        st.pop();
        
        if(check.at(stTop)) continue;
        check[stTop] = true;
        cout << stTop + 1 << " ";
        
        sort(vec[stTop].begin(), vec[stTop].end(), greater<int>());
        for(int i = 0; i < vec[stTop].size(); i++) {
            if(!check[vec[stTop].at(i)]) st.push(vec[stTop].at(i));
        }
        
    }
}

void BFS(int startPoint) {
    q.push(startPoint);
    
    while(!q.empty()) {
        int qFront = q.front();
        q.pop();
        
        if(check.at(qFront)) continue;
        check[qFront] = true;
        cout << qFront + 1 << " ";
        
        sort(vec[qFront].begin(), vec[qFront].end());
        for(int i = 0; i < vec[qFront].size(); i++) {
            if(!check[vec[qFront].at(i)]) q.push(vec[qFront].at(i));
        }
    }
}

int main() {
    int N, M, V, start, end; //정점 개수, 간선 개수, 탐색 시작할 번호
    cin >> N >> M >> V;
    
    for(int i = 0; i < M; i++) {
        cin >> start >> end;
        vec[start - 1].push_back(end - 1);
        vec[end - 1].push_back(start - 1);
        check.push_back(false);
    }
    
    DFS(V - 1);
    
    for(int i = 0; i < 1000; i++) check.at(i) = false;
    cout << "\n";
    
    BFS(V - 1);
}
