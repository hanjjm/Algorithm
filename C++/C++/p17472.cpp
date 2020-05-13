//
//  p17472.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/13.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int matrix[102][102] = {0, };
bool visited[102][102] = {false, };
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bridge[7][7];
int cycle[7];
int number = 1;
int answer = 0;

void initMatrix(int row, int column) {
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) cin >> matrix[i][j];
    }
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) bridge[i][j] = 100;
    }
}

void islandNumbering(int row, int column) {
    stack<pair<int, int>> st;
    
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) {
            int flag = 0;
            if(matrix[i][j] && !visited[i][j]) {
                st.push(make_pair(i, j));
                visited[i][j] = true;
                matrix[i][j] = number;
                
                while(!st.empty()) {
                    int first = st.top().first;
                    int second = st.top().second;
                    st.pop();
                    
                    for(int i = 0; i < 4; i++) {
                        if(matrix[first + direction[i][0]][second + direction[i][1]]
                           && !visited[first + direction[i][0]][second + direction[i][1]]) {
                            matrix[first + direction[i][0]][second + direction[i][1]] = number;
                            visited[first + direction[i][0]][second + direction[i][1]] = true;
                            st.push(make_pair(first + direction[i][0], second + direction[i][1]));
                        }
                    }
                    flag = 1;
                }
            }
            if(flag) number++;
        }
    }
}

void calculateBridge(int row, int column) {
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) {
            
            if(matrix[i][j] != 0) {
                int from = matrix[i][j];
                for(int k = 1; k <= column; k++) {
                    if(matrix[i][j + k] == from) break;
                    if(matrix[i][j] != matrix[i][j + k] && matrix[i][j + k] != 0 && j + k < 102) {
                        int to = matrix[i][j + k];
                        if(k == 1 || k == 2) break;
                        else {
                            bridge[from][to] = min(bridge[from][to], k - 1);
                            break;
                        }
                    }
                }
                for(int k = 1; k <= column; k++) {
                    if(matrix[i][j - k] == from) break;
                    if(matrix[i][j] != matrix[i][j - k] && matrix[i][j - k] != 0 && j - k > 0) {
                        int to = matrix[i][j - k];
                        if(k == 1 || k == 2) break;
                        else {
                            bridge[from][to] = min(bridge[from][to], k - 1);
                            break;
                        }
                    }
                }
                for(int k = 1; k <= row; k++) {
                    if(matrix[i + k][j] == from) break;
                    if(matrix[i][j] != matrix[i + k][j] && matrix[i + k][j] != 0 && i + k < 102) {
                        int to = matrix[i + k][j];
                        if(k == 1 || k == 2) break;
                        else {
                            bridge[from][to] = min(bridge[from][to], k - 1);
                            break;
                        }
                    }
                }
                for(int k = 1; k <= row; k++) {
                    if(matrix[i - k][j] == from) break;
                    if(matrix[i][j] != matrix[i - k][j] && matrix[i - k][j] != 0 && i - k > 0) {
                        int to = matrix[i - k][j];
                        if(k == 1 || k == 2) break;
                        else {
                            bridge[from][to] = min(bridge[from][to], k - 1);
                            break;
                        }
                    }
                }
            }
            
        }
    }
    
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(bridge[i][j] == 100) bridge[i][j] = 0;
        }
    }
}

void initCycle() {
    for(int i = 0; i < 7; i++) cycle[i] = i;
}

int _find(int num) {
    if(cycle[num] == num) return num;
    else return cycle[num] = _find(cycle[num]);
}

void _union(int first, int second) {
    first = _find(first);
    second = _find(second);
    if(first < second) cycle[second] = first;
    else cycle[first] = second;
}

void printMatrix(int row, int column) {
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) cout << matrix[i][j];
        cout << endl;
    }
}

void printBridge(int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) cout << bridge[i][j];
        cout << endl;
    }
}

void solve(int row, int column) {
    vector<int> vec;
    for(int i = 0; i < 7; i++) {
        for(int j = 0; j < 7; j++) {
            if(bridge[i][j] != 0) {
                vec.push_back(bridge[i][j]);
                bridge[j][i] = 0;
            }
        }
    }
    
    if(vec.empty() || row * column <= 3) {
        cout << -1 << endl;
        return;
    }
    
    sort(vec.begin(), vec.end());
    
    while(true) {
        for(int i = 1; i <= 7; i++) {
            for(int j = 1; j <= 7; j++) {
                if(!vec.empty()) {
                    if(bridge[i][j] == vec[0]) {
                        if(_find(i) != _find(j)) {
                            answer += vec[0];
                            _union(i, j);
                        }
                        vec.erase(vec.begin() + 0);
                    }
                }
            }
        }
        if(vec.empty()) break;
    }
    
    for(int i = 1; i <= number - 1; i++) {
        if(_find(i) != 1) {
            cout << -1 << endl;
            return;
        }
    }
    cout << answer << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    initMatrix(N, M);
    islandNumbering(N, M);
    calculateBridge(N, M);
    initCycle();
//    printMatrix(N, M); // 테스트용
//    cout << endl;
//    printBridge(N, M); // 테스트용
    solve(N, M);
}
