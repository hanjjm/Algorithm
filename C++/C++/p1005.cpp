//
//  p1005.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/20.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int buildingNum, ruleNum, target;
int building[1001], timeArr[1001], indegree[1001];
vector<vector<int>> rule(100001);
vector<int> answer;

void init() {
    for(int i = 0; i < 1001; i++) {
        building[i] = 0;
        timeArr[i] = 0;
        indegree[i] = 0;
    }
    
    for(int i = 0; i < 100001; i++) rule[i].clear();
}

void input() {
    cin >> buildingNum >> ruleNum;
    for(int i = 1; i <= buildingNum; i++) cin >> building[i];
    for(int i = 0; i < ruleNum; i++) {
        int from, to;
        cin >> from >> to;
        rule[from].push_back(to);
        indegree[to]++;
    }
    cin >> target;
}

void solve() {
    queue<int> q;
    for(int i = 1; i <= buildingNum; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            timeArr[i] = building[i];
        }
    }
    
    while(!q.empty()) {
        int qFront = q.front();
        q.pop();
        
        for(int i = 0; i < rule[qFront].size(); i++) {
            int next = rule[qFront][i];
            indegree[next]--;
            
            if(indegree[next] == 0) q.push(next);
            timeArr[next] = max(timeArr[next], timeArr[qFront] + building[next]);
        }
    }
    
    
//    for(int i = 1; i <= buildingNum; i++) cout << timeArr[i] << " ";
//    cout << timeArr[target] << endl;
    answer.push_back(timeArr[target]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        init();
        input();
        solve();
    }
    
    for(int i = 0; i < answer.size(); i++) cout << answer[i] << endl;
    
    return 0;
}
