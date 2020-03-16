//
//  p10866.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase;
    cin >> testCase;
    deque<int> deque;
    
    for(int i = 0; i < testCase; i++) {
        string order;
        cin >> order;
        if(order == "push_front") {
            int pushNum;
            cin >> pushNum;
            deque.push_front(pushNum);
        } else if(order == "push_back") {
            int pushNum;
            cin >> pushNum;
            deque.push_back(pushNum);
        } else if(order == "pop_front") {
            if(deque.empty()) cout << "-1" << endl;
            else {
                cout << deque.front() << endl;
                deque.pop_front();
            }
        } else if(order == "pop_back") {
            if(deque.empty()) cout << "-1" << endl;
            else {
                cout << deque.back() << endl;
                deque.pop_back();
            }
        } else if(order == "size") {
            cout << deque.size() << endl;
        } else if(order == "empty") {
            if(deque.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        } else if(order == "front") {
            if(deque.empty()) cout << "-1" << endl;
            else cout << deque.front() << endl;
        } else if(order == "back") {
            if(deque.empty()) cout << "-1" << endl;
            else cout << deque.back() << endl;
        }
    }
}
