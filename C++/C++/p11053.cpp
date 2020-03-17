//
//  p11053.cpp
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
    
    int DP[testCase];
    int array[testCase];
    DP[0] = 1;
    int flag = 1;
    for(int i = 1; i < testCase; i++) DP[i] = 0;
    for(int i = 0; i < testCase; i++) cin >> array[i];
    for(int i = 1; i < testCase; i++) {
        for(int j = 0; j < i; j++) {
            if(array[j] < array[i]) {
                DP[i] = max(DP[i], DP[j]);
                flag = 0;
            } else if(DP[i] == 0) DP[i] = 1;
        }
        if(flag == 0) DP[i]++;
        flag = 1;
    }
    
    int max = 0;
    for(int i = 0; i < testCase; i++){
        if(max <= DP[i]) max = DP[i];
    }
    
    cout << max << endl;
}
