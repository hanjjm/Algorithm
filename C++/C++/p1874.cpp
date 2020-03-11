//
//  p1874.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/12.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    int array[num];
    stack<int> stack;
    vector<char> vector;
    
    for(int i = 0; i < num; i++) {
        int tempNum;
        scanf("%d", &tempNum);
        array[i] = tempNum;
    }
    
    int M = 0;
    for(int i = 1; i <= num; i++) {
        stack.push(i);
        vector.push_back('+');
    
        while(!stack.empty() && stack.top() == array[M]) {
            stack.pop();
            vector.push_back('-');
            M++;
        }
    }
        
    if(stack.empty()) {
        for(int j = 0; j < vector.size(); j++) printf("%c\n", vector.at(j));
        
    } else cout << "NO";
}
