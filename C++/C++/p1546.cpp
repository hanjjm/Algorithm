//
//  p1546.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/21.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    double score[testCase];
    for(int i = 0; i < testCase; i++) cin >> score[i];
    sort(score, score + testCase);
    double max = score[testCase - 1];
    
    for(int i = 0; i < testCase; i++) score[i] = score[i] / max * 100;
    max = 0;
    for(int i = 0; i < testCase; i++) max += score[i];
    
    cout << max / testCase;
}
