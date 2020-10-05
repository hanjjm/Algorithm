//
//  s5648.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/04.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<vector<int>> vec, checkNode;
int num, minX, maxX, minY, maxY, answer, len;
unordered_map<int, unordered_map<int, int>> um;

void input() {
    minX = 1001, maxX = -1001, minY = 1001, maxY = -1001;
    for(int i = 0; i < num; i++) {
        vector<int> node;
        int x, y, dir, energy;
        cin >> x >> y >> dir >> energy;
        node.push_back(x);
        node.push_back(y);
        node.push_back(dir);
        node.push_back(energy);
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
        vec.push_back(node);
    }
}

void move() {
    um.clear();
    int vecSize = vec.size();
    for(int i = 0; i < vecSize; i++) {
        if(vec[i][2] == 0) vec[i][1]++;
        else if(vec[i][2] == 1) vec[i][1]--;
        else if(vec[i][2] == 2) vec[i][0]--;
        else vec[i][0]++;
        
        um[vec[i][0]][vec[i][1]]++;
    }
}

void deleteNode() {
    for(int i = 0; i < vec.size(); i++) {
        if(um[vec[i][0]][vec[i][1]] >= 2) {
            answer += vec[i][3];
            vec.erase(vec.begin() + i);
            i--;
        }
    }
}

void solve() {
    for(int i = 0; i <= 1000; i++) {
        move();
        deleteNode();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        cin >> num;
        vec.clear();
        answer = 0;
        input();
        solve();
        cout << "#" << i + 1 << " " << answer << endl;
    }
    
    return 0;
}
