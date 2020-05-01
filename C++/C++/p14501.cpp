//
//  p14501.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/01.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int day;
    cin >> day;
    int DP[day + 1];
    int time[day + 1], cost[day + 1];
    time[0] = 0; cost[0] = 0;
    for(int i = 0; i < day; i++) cin >> time[i + 1] >> cost[i + 1];
    DP[0] = 0; // 안쓰는거
//    if(time[0]) DP[1] = cost[1];
//    else DP[1] = 0;
    
    for(int i = 1; i <= day; i++) {
        if(i + time[i] > day) continue;
        for(int j = 1; j <= i; j++) {
            DP[i] = max(DP[i + time[i]] + cost[i], DP[i]);
        }
    }
    
    cout << DP[day];
}
