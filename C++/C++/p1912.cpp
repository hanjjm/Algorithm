//
//  p1912.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/17.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    int array[testCase];
    int DP[testCase];
    for(int i = 0; i < testCase; i++) cin >> array[i];
    DP[0] = array[0];
    
    for(int i = 1; i < testCase; i++) {
        DP[i] = max(DP[i - 1] + array[i], array[i]);
    }
    
    int maxNum = -9999;
    for(int i = 0; i < testCase; i++) if(maxNum <= DP[i]) maxNum = DP[i];
    cout << maxNum << endl;
}
