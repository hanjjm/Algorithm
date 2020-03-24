//
//  p11399.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/24.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int people;
    cin >> people;
    int withdrawalTime[people];
    for(int i = 0; i < people; i++) cin >> withdrawalTime[i];
    
    sort(withdrawalTime, withdrawalTime + people);
    int count = 0;
    for(int i = 0; i < people; i++) {
        count += withdrawalTime[i];
        if(i + 1 != people) withdrawalTime[i + 1] += withdrawalTime[i];
    }
    cout << count;
}
