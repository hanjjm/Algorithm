//
//  p10773.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stack;
    int num;
    cin >> num;
    
    for(int i = 0; i < num; i++) {
        int tempNum;
        cin >> tempNum;
        if(tempNum != 0) stack.push(tempNum);
        else stack.pop();
    }
    
    int result = 0;
    for(int i = 0; !stack.empty(); i++) {
        result += stack.top();
        stack.pop();
    }
    
    cout << result;
}
