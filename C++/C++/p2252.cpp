//
//  p2252.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/20.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<vector<int>> vec(32001);
    queue<int> q;
    
    int peopleNum, ruleNum;
    cin >> peopleNum >> ruleNum;
    
    int indegree[32001] = {0, };
    
    for(int i = 0; i < ruleNum; i++) {
        int from, to;
        cin >> from >> to;
        vec[from].push_back(to);
        indegree[to]++;
    }
    
    for(int i = 1; i <= peopleNum; i++) {
        if(indegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()) {
        int qFront = q.front();
        q.pop();
        cout << qFront << " ";
        
        for(int i = 0; i < vec[qFront].size(); i++) {
            int next = vec[qFront][i];
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }
    
    return 0;
}
