//
//  p2675.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/23.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    
    while(testCase --> 0) {
        int repetition;
        string word;
        cin >> repetition >> word;
        
        for(int i = 0; i < word.size(); i++) {
            for(int j = 0; j < repetition; j++) cout << word.at(i);
        }
        cout << endl;
    }
}
