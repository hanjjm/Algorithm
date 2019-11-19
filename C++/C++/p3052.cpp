//
//  p3052.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/20.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int rest[10];
    int restNum;
    
    for(int i = 0; i < 10; i++) {
        cin >> restNum;
        rest[i] = restNum % 42;
    }
    
    sort(rest, rest+ 10);
    int result = 1;
    
    for(int i = 1; i < 10; i++) {
        if(rest[i - 1] != rest[i]) result++;
    }
    
    cout << result;
}
