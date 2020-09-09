//
//  twoPointer2.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/09.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc, target, answer = 987654321;
    cin >> tc >> target;
    int arr[100000] = {0, };
    
    for(int i = 0; i < tc; i++) cin >> arr[i];
    int start = 0, end = 0;
    int plus = 0;
    
    while(start <= end) {
        if(plus >= target) { // 합격
            answer = min(answer, end - start);
            plus -= arr[start];
            start++;
        } else if(end == tc) break;
        else {
            plus += arr[end];
            end++;
        }
    }
    
    if(answer != 987654321) cout << answer;
    else cout << 0;
    return 0;
}
