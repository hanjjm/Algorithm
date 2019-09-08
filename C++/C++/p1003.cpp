//
//  p1003.cpp
//  C++
//
//  Created by KimHanJu on 09/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> zeroResult, oneResult;
    
    int testCase;
    cin >> testCase;
    int result[testCase];
    
    zeroResult.push_back(1);
    zeroResult.push_back(0);
    oneResult.push_back(0);
    oneResult.push_back(1);
    
    int setNum = 2;
    
    while(setNum != 41) {
        zeroResult.push_back(zeroResult.at(setNum-1) + zeroResult.at(setNum-2));
        oneResult.push_back(oneResult.at(setNum-1) + oneResult.at(setNum-2));
        setNum++;
    }
    
    for(int i = 0; i < testCase; i++) cin >> result[i];
    
    for(int i = 0; i < testCase; i++) cout << zeroResult.at(result[i]) << " " << oneResult.at(result[i]) << "\n";
    
    return 0;
}
