//
//  p9372.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int nation[1000] = {0, };
vector<vector<int>> airPlane(10000);

void initArr() {
    for(int i = 0; i < 1000; i++) nation[i] = 0;
}

void solve() {
    
}

int main() {
    int tc;
    cin >> tc;
    
    for(int i = 0; i < tc; i++) {
        int nationCount, airPlaneCount;
        cin >> nationCount >> airPlaneCount;
        for(int j = 0; j < airPlaneCount; j++) {
            initArr();
            airPlane.clear();
            int from, to;
            cin >> from >> to;
            airPlane[from].push_back(to);
            airPlane[to].push_back(from);
        }
        solve();
    }
    
    cout << "2";
    return 0;
}
