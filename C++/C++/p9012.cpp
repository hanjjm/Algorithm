//
//  p9012.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        string parenthesisString;
        cin >> parenthesisString;
        stack<int> stack;
        for(int j = 0; j < parenthesisString.size(); j++) {
            if(parenthesisString[j] == '(') stack.push(0);
            else {
                if(stack.empty()) {
                    stack.push(-1);
                    break;
                } else stack.pop();
            }
        }
        if(stack.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
