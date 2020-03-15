//
//  p11866.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase, K;
    cin >> testCase >> K;
    queue<int> queue;
    
    cout << "<";
    for(int i = 1; i <= testCase; i++) queue.push(i);
    while(queue.size() != 0) {
        for(int i = 1; i <= K - 1; i++) {
            queue.push(queue.front());
            queue.pop();
        }
        cout << queue.front();
        queue.pop();
        if(!queue.empty()) cout << ", ";
    }
    cout << ">";
}
