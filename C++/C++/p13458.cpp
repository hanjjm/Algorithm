//
//  p13458.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/28.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long answer = 0;
    int classroom, all, sub;
    cin >> classroom;
    int people[classroom];
    for(int i = 0; i < classroom; i++) cin >> people[i];
    cin >> all >> sub;
    for(int i = 0; i < classroom; i++) {
        people[i] -= all;
        if(people[i] <= 0) continue;
        if(people[i] % sub == 0) answer += people[i] / sub;
        else answer += people[i] / sub + 1;
    }
    
    cout << answer + classroom;
}
