//
//  p2562.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/15.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int array[9];
    
    for(int i = 0; i < 9; i++) cin >> array[i];
    int maxIndex = 0, maxNum = array[0];
    for(int i = 1; i < 9; i++) {
        if(maxNum < array[i]) {
            maxNum = array[i];
            maxIndex = i;
        }
    }
    
    cout << array[maxIndex] << endl << maxIndex + 1 << endl;

    return 0;
}
