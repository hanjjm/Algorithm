//
//  binarySearch6.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/09.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc, target;
    cin >> tc >> target;
    int height[1000000] = {0, };
    for(int i = 0; i < tc; i++) cin >> height[i];
    
    int answer = 0;
    int left = 1, right = 2000000000;
    int mid = (left + right) / 2;
    
    while(left <= right) {
        mid = (left + right) / 2;
        long long plus = 0;
        
        for(int i = 0; i < tc; i++) {
            if(height[i] >= mid) plus += height[i] - mid;
        }
        
        if(plus < target) { // 실패
            right = mid - 1;
        } else { // 성공
            if(answer < mid) answer = mid;
            left = mid + 1;
        }
    }
    
    cout << answer;
    return 0;
}
