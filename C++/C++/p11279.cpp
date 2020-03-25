//
//  p11279.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/25.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase, temp;
    priority_queue<int> pq;
    cin >> testCase;
    
    while(testCase) {
        cin >> temp;
        if(temp == 0) {
            if(pq.empty()) cout << "0" << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else pq.push(temp);
        testCase--;
    }
}
