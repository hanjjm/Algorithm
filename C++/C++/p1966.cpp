//
//  p1966.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase;
    cin >> testCase;

    while(testCase --> 0) {
        int N, M; //문서의 수, 현재 어느 위치에 있는지
        int index = 0;
        queue<pair<int, int>> queue;
        priority_queue<int> p_queue;
        
        cin >> N >> M;
        for(int i = 0; i < N; i++) {
            int priority;
            cin >> priority;
            queue.push({i, priority});
            p_queue.push(priority);
        }
        
        while(!queue.empty()) {
            int number = queue.front().first;
            int prior = queue.front().second;
            queue.pop();
            
            if(p_queue.top() == prior) {
                p_queue.pop();
                index++;
                if(number == M) {
                    cout << index << endl;
                    break;
                }
            } else queue.push({number, prior});
        }
    }
}
