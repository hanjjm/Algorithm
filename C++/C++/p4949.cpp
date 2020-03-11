//
//  p4949.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/11.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    while(true) {
        string str;
        getline(cin, str);
        if(str == ".") break;
        
        stack<char> stack;
        
        for(int i = 0; i < str.size(); i++) {
            if(str.at(i) == '(') {
                stack.push('(');
            } else if(str.at(i) == ')') {
                if(stack.empty()) {
                    stack.push('*');
                    break;
                } else if(stack.top() == '(') {
                    stack.pop();
                } else break;
            } else if(str.at(i) == '[') {
                stack.push('[');
            } else if(str.at(i) == ']') {
                if(stack.empty()) {
                    stack.push('*');
                    break;
                } else if(stack.top() == '[') {
                    stack.pop();
                } else break;
            }
        }
        
        if(stack.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
