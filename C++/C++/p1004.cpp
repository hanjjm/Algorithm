//
//  p1004.cpp
//  C++
//
//  Created by KimHanJu on 09/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double getDistance(int x, int y, int planetX, int planetY) {
    return sqrt(pow(x - planetX, 2) + pow(y - planetY, 2));
}

int main(int argc, const char * argv[]) {
    vector<int> result;
    
    int testCase;
    int x1, y1;
    int x2, y2;
    int x3, y3, r3;
    int planetCount, resultCount = 0;
    double distanceStart, distanceArrive;
    
    cin >> testCase;
    
    while(testCase --> 0) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> planetCount;
        
        while(planetCount --> 0) {
            cin >> x3 >> y3 >> r3;
            distanceStart = getDistance(x1, y1, x3, y3);
            distanceArrive = getDistance(x2, y2, x3, y3);
            
            if((r3 > distanceArrive && r3 < distanceStart)
               || (r3 < distanceArrive && r3 > distanceStart)) {
                resultCount++;
            }
        }
        
        result.push_back(resultCount);
        resultCount = 0;
    }

    for(int value : result) cout << value << "\n";
    
    return 0;
}
