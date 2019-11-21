//
//  p4344.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/22.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    while(testCase --> 0) {
        int testNum;
        cin >> testNum;
        int score[testNum];
        double sum = 0;
        for(int i = 0; i < testNum; i++) {
            cin >> score[i];
            sum += score[i];
        }
        double mean = sum / testNum;
        
        double upperNum = 0;
        for(int i = 0; i < testNum; i++) {
            if(score[i] > mean) upperNum++;
        }
        printf("%.3f%%\n", round((double)upperNum / (double)testNum * 100000) / 1000);
    }
}
