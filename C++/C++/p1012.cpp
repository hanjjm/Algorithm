//
//  p1012.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/31.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int matrix[50][50];

void init() {
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) matrix[i][j] = 0;
    }
}

void DFS(int width, int height, int num) {
    int result = 0;
    stack<pair<int, int>> st;
    
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(matrix[i][j]) {
                st.push(make_pair(i, j));
                matrix[i][j] = 0;

                while(!st.empty()) {
                    pair<int, int> now = st.top();
                    st.pop();
                    
                    for(int k = 0; k < 4; k++) {
                        if(now.first + direction[k][0] >= 0 && now.second + direction[k][1] >= 0
                           && now.first + direction[k][0] <= height && now.second + direction[k][1] <= width) {
                            if(matrix[now.first + direction[k][0]][now.second + direction[k][1]] == 1) {
                                matrix[now.first + direction[k][0]][now.second + direction[k][1]] = 0;
                                st.push(make_pair(now.first + direction[k][0], now.second + direction[k][1]));
                            }
                        }
                    }
                }
                result++;
            }
        }
    }
    
    cout << result << endl;
}

int main() {
    int testCase;
    cin >> testCase;
    int width[testCase], height[testCase], num[testCase];
    for(int i = 0; i < testCase; i++) {
        init();
        cin >> width[i] >> height[i] >> num[i];
        
        for(int i = 0; i < num[i]; i++) {
            int x, y;
            cin >> x >> y;
            matrix[y][x] = 1;
        }
        DFS(width[i], height[i], num[i]);
    }
    
}
