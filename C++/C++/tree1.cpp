//
//  tree1.cpp
//  C++
//
//  Created by KimHanJu on 2020/08/30.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> node(100001);
int parent[100001] = {0, };
int visited[100001] = {0, };

void findParent(int number) {
    for(int i = 0; i < node[number].size(); i++) {
        if(visited[node[number][i]] == 0) {
            parent[node[number][i]] = number;
            visited[node[number][i]] = 1;
            findParent(node[number][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        int from, to;
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }
    
    visited[1] = 1;
    findParent(1);
    
    for(int i = 2; i <= testCase; i++) cout << parent[i] << "\n";
    
    return 0;
}
