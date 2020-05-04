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
int matrix[52][52] = {0, };
int visited[52][52] = {0, };


void init() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void matrixInit() {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            matrix[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

void DFS(int width, int height) {
    int result = 0;
    stack<pair<int, int>> st;

    for(int i = 1; i <= height; i++) {
        for(int j = 1; j <= width; j++) {
            if(matrix[i][j] == 1 && visited[i][j] == 0) {
                st.push(make_pair(i, j));
                visited[i][j] = 1;
                while(!st.empty()) {
                    pair<int, int> now = st.top();
                    st.pop();
                    for(int k = 0; k < 4; k++) {
                        if(matrix[now.first + direction[k][0]][now.second + direction[k][1]] == 1
                           && visited[now.first + direction[k][0]][now.second + direction[k][1]] == 0) {
                            visited[now.first + direction[k][0]][now.second + direction[k][1]] = 1;
                            st.push(make_pair(now.first + direction[k][0], now.second + direction[k][1]));
                        }
                    }
                }
                result++;
            }
        }
    }
    cout << result << endl;;
}

int main() {
    init();
    int testCase;
    cin >> testCase;
    int width[testCase], height[testCase], num[testCase];
    for(int i = 0; i < testCase; i++) {
        matrixInit();
        cin >> width[i] >> height[i] >> num[i];
        for(int j = 0; j < num[i]; j++) {
            int x, y;
            cin >> x >> y;
            matrix[y + 1][x + 1] = 1;
        }
        DFS(width[i], height[i]);
    }
}
