//
//  p2667.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/26.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int matrix[26][26];
bool check[26][26];
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void DFS(int len) {
    stack<pair<int, int>> st;
    vector<int> result;
    int roomCount = 0;
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(check[i][j]) {
                roomCount = 0;
                check[i][j] = 0;
                st.push(make_pair(i, j));
                
                while(!st.empty()) {
                    roomCount++;
                    pair<int, int> stTop = st.top();
                    st.pop();
                    
                    for(int k = 0; k < 4; k++) {
                        if(check[stTop.first + direction[k][0]][stTop.second + direction[k][1]]) {
                            check[stTop.first + direction[k][0]][stTop.second + direction[k][1]] = 0;
                            st.push(make_pair(stTop.first + direction[k][0], stTop.second + direction[k][1]));
                        }
                    }
                }
                result.push_back(roomCount);
            }
        }
    }
    
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++) cout << result[i] << endl;
}

int main() {
    int line;
    cin >> line;
    
    for(int i = 0; i < line; i++) {
        string eachLine;
        cin >> eachLine;
        char temp[1];
        for(int j = 0; j < line; j++) {
            temp[0] = eachLine[j];
            matrix[i][j] = atoi(temp);
            if(atoi(temp)) check[i][j] = true;
            else check[i][j] = false;
        }
    }
    
    DFS(line);
}
