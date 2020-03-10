//
//  p10828.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    stack<int> stack;
    
    for(int i = 0; i < num; i++) {
        string order;
        cin >> order;
        
        if(order == "push") {
            int stNum;
            cin >> stNum;
            stack.push(stNum);
        } else if(order == "pop") {
            if(stack.size() == 0) cout << "-1" << endl;
            else {
                cout << stack.top() << endl;
                stack.pop();
            }
        } else if(order == "size") {
            cout << stack.size() << endl;
        } else if(order == "empty") {
            if(stack.empty()) cout << "1" << endl;
            else cout << "0" << endl;
        } else if(order == "top") {
            if(stack.empty()) cout << "-1" << endl;
            else cout << stack.top() << endl;
        }
    }
}
