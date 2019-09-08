//
//  p1002.cpp
//  C++
//
//  Created by KimHanJu on 09/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int caculateResult(int x1, int y1, int r1, int x2, int y2, int r2, double distance) {
    int result = 0;
    
    if((r1 + r2 == distance && abs(r1 - r2) < distance) || abs(r1 - r2) == distance) {
        result = 1;
    }
    
    if (r1 + r2 > distance && abs(r1 - r2) < distance) {
        result = 2;
    }
    
    if (r1 == r2 && distance == 0) {
        result = -1;
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> result;
    
    int x1, y1, r1;
    int x2, y2, r2;
    int testCase;
    
    cin >> testCase;
    
    while(testCase --> 0) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        
        result.push_back(caculateResult(x1, y1, r1, x2, y2, r2, distance));
    }
    
    for(int value : result) {
        cout << value << "\n";
    }
    
    return 0;
}
