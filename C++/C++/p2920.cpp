//
//  p2920.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/18.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int array[8], result[8];;
    for(int i = 0; i < 8; i++) cin >> array[i];
    
    int index = array[1] - array[0];
    int count = 0;
    for(int i = 1; i < 8; i++) {
        if(array[i] - array[i - 1] == index) count++;
    }
    
    if(count == 7) {
        if(index > 0) cout << "ascending";
        if(index < 0) cout << "descending";
    } else cout << "mixed";
}
