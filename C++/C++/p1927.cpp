//
//  p1927.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/08.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    priority_queue <int, vector<int>, greater<int>> pq;
    
    int num;
    for(int i = 0; i < testCase; i++) {
        cin >> num;
        if(num == 0) {
            if(pq.empty()) cout << "0" << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        } else pq.push(num);
    }
    
    return 0;
}
