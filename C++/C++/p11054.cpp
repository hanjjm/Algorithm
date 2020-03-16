//
//  p11054.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int length;
    cin >> length;
    
    int array[length];
    for(int i = 0;  i < length; i++) {
        int tempNum;
        cin >> tempNum;
        array[i] = tempNum;
    }
    
    int left[length];
    int right[length];
    left[0] = 1;
    right[length - 1] = 1;
    
    for(int i = 1; i < length; i++) {
        left[i] = 1;
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j] && left[i] < left[j] + 1) left[i] = left[j] + 1;
        }
    }
    
    for(int i = length - 2; i >= 0; i--) {
        right[i] = 1;
        for(int j = length - 1; j > i; j--) {
            if(array[i] > array[j] && right[i] < right[j] + 1) right[i] = right[j] + 1;
        }
    }
    
    int result = 0;
    for(int i = 0; i < length; i++) {
        if(result < left[i] + right[i] - 1) result = left[i] + right[i] - 1;
    }
    
    cout << result << endl;
}
