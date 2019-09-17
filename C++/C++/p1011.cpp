//
//  p1011.cpp
//  C++
//
//  Created by KimHanJu on 18/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCase;
    int x, y;
    vector<int> vector;
    cin >> testCase;
    
    while(testCase --> 0) {
        int result = 1, compareNumber = 1, tempNumber = 2;
        cin >> x >> y;
        int distance = y - x;
        
        for(int i = 1; i <= distance; i++) {
            if(i % 2 == 0) compareNumber++;
            if(tempNumber <= distance) result++;
            tempNumber += compareNumber;
            if(tempNumber > distance) break;
        }
        
        vector.push_back(result);
    }
    
    for(int value : vector) cout << value << "\n";
    return 0;
}
