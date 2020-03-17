//
//  p2579.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/17.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    int point[testCase];
    int DP[testCase];
    for(int i = 0; i < testCase; i++) {
        int eachPoint;
        cin >> eachPoint;
        point[i] = eachPoint;
    }
    
    DP[0] = point[0];
    DP[1] = max(point[1], point[0] + point[1]);
    DP[2] = max(point[0] + point[2], point[1] + point[2]);
    
    for(int i = 3; i < testCase; i++) {
        DP[i] = max(DP[i - 3] + point[i - 1] + point[i], DP[i - 2] + point[i]);
    }
    
    cout << DP[testCase - 1] << endl;
}
