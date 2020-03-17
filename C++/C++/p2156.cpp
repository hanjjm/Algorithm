//
//  p2156.cpp
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
    int podoju[testCase];
    int DP[testCase];
    
    for(int i = 0; i < testCase; i++) {
        int eachPodo;
        cin >> eachPodo;
        podoju[i] = eachPodo;
    }
    
    if(testCase > 3) {
        DP[0] = podoju[0];
        DP[1] = podoju[0] + podoju[1];
        
        for(int i = 2; i < testCase; i++) {
            DP[i] = max(DP[i - 3] + podoju[i - 1] + podoju[i], DP[i - 2] + podoju[i]);
            DP[i] = max(DP[i], DP[i - 1]);
        }
        
        cout << DP[testCase - 1] << endl;
    } else {
        if(testCase == 1) cout << podoju[0] << endl;
        else cout << podoju[0] + podoju[1] << endl;
    }
}
