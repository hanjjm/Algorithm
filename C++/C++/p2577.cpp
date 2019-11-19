//
//  p2577.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/19.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    int multiNumber;
    int result[10];
    for(int i = 0; i < 10; i++) result[i] = 0;
    cin >> A >> B >> C;
    multiNumber = A * B * C;
    
    for(int i = 0; multiNumber != 0; i++) {
        result[multiNumber % 10]++;
        multiNumber /= 10;
    }
    
    for(int i = 0; i < 10; i++) cout << result[i] << endl;
}
