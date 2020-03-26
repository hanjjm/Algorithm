//
//  p2606.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/26.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<vector<int>> connect(100);
vector<bool> check(100);

void DFS() {
    stack<int> st;
    int count = 0;
    st.push(0);
    
    while(!st.empty()) {
        int stTop = st.top();
        st.pop();
        
        if(check[stTop]) continue;
        check[stTop] = true;
        count++;
        
        for(int i = 0; i < connect[stTop].size(); i++) {
            st.push(connect[stTop].at(i));
        }
    }
    
    cout << count - 1;
}

int main() {
    int computer, edge;
    cin >> computer >> edge;
    
    int start, end;
    for(int i = 0; i < edge; i++) {
        cin >> start >> end;
        connect[start - 1].push_back(end - 1);
        connect[end - 1].push_back(start - 1);
    }
    
    for(int i = 0; i < 100; i++) check.at(i) = false;
    DFS();
}
