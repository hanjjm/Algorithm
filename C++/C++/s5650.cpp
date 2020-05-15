//
//  s5650.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/12.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int testCase, N;
int matrix[102][102] = {0, };
int maxNum = 0;
void up(int, int, int, int, int);
void down(int, int, int, int, int);
void right(int, int, int, int, int);
void left(int, int, int, int, int);

void initMatrix() {
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) matrix[i][j] = 0;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> matrix[i][j];
    }
    
    for(int i = 0; i < N + 2; i++) matrix[i][0] = -2;
    for(int i = 0; i < N + 2; i++) matrix[i][N + 1] = -2;
    for(int i = 0; i < N + 2; i++) matrix[0][i] = -2;
    for(int i = 0; i < N + 2; i++) matrix[N + 1][i] = -2;
}

void printBoard() {
    for(int i = 0; i < N + 2; i++) {
        for(int j = 0; j < N + 2; j++) cout << matrix[i][j];
        cout << endl;
    }
}

void up(int x, int y, int count, int endX, int endY) {
    if(x == endX && y == endY) {
        maxNum = max(maxNum, count);
        return;
    }
    if(matrix[x][y] == 0) {
        up(x - 1, y, count, endX, endY);
    } else if(matrix[x][y] == 1 || matrix[x][y] == 4 || matrix[x][y] == 5 || matrix[x][y] == -2) {
        down(x + 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == 2) {
        right(x, y + 1, count + 1, endX, endY);
    } else if(matrix[x][y] == 3) {
        left(x, y - 1, count + 1, endX, endY);
    } else if(matrix[x][y] == -1) {
        maxNum = max(maxNum, count);
        return;
    } else {
        for(int i = 0; i <= 101; i++) {
            for(int j = 0; j <= 101; j++) {
                if(matrix[i][j] == matrix[x][y]) {
                    if(i != x && j != y) {
                        up(i - 1, j, count, endX, endY);
                        break;
                    }
                }
            }
        }
    }
}

void down(int x, int y, int count, int endX, int endY) {
    if(x == endX && y == endY) {
        maxNum = max(maxNum, count);
        return;
    }
    if(matrix[x][y] == 0) {
        down(x + 1, y, count, endX, endY);
    } else if(matrix[x][y] == 2 || matrix[x][y] == 3 || matrix[x][y] == 5 || matrix[x][y] == -2) {
        up(x - 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == 1) {
        right(x, y + 1, count + 1, endX, endY);
    } else if(matrix[x][y] == 4) {
        left(x, y - 1, count + 1, endX, endY);
    } else if(matrix[x][y] == -1) {
        maxNum = max(maxNum, count);
        return;
    } else {
        for(int i = 0; i <= 101; i++) {
            for(int j = 0; j < 101; j++) {
                if(matrix[i][j] == matrix[x][y]) {
                    if(i != x && j != y) {
                        down(i + 1, j, count, endX, endY);
                        break;
                    }
                }
            }
        }
    }
}

void right(int x, int y, int count, int endX, int endY) {
    if(x == endX && y == endY) {
        maxNum = max(maxNum, count);
        return;
    }
    if(matrix[x][y] == 0) {
        right(x, y + 1, count, endX, endY);
    } else if(matrix[x][y] == 1 || matrix[x][y] == 2 || matrix[x][y] == 5 || matrix[x][y] == -2) {
        left(x, y - 1, count + 1, endX, endY);
    } else if(matrix[x][y] == 3) {
        down(x + 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == 4) {
        up(x - 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == -1) {
        maxNum = max(maxNum, count);
        return;
    } else {
        for(int i = 0; i <= 101; i++) {
            for(int j = 0; j <= 101; j++) {
                if(matrix[i][j] == matrix[x][y]) {
                    if(i != x && j != y) {
                        right(i, j + 1, count, endX, endY);
                        break;
                    }
                }
            }
        }
    }
}

void left(int x, int y, int count, int endX, int endY) {
    if(matrix[x][y] == 0) {
        left(x, y - 1, count, endX, endY);
    } else if(matrix[x][y] == 3 || matrix[x][y] == 4 || matrix[x][y] == 5 || matrix[x][y] == -2) {
        right(x, y + 1, count + 1, endX, endY);
    } else if(matrix[x][y] == 2) {
        down(x + 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == 1) {
        up(x - 1, y, count + 1, endX, endY);
    } else if(matrix[x][y] == -1) {
        maxNum = max(maxNum, count);
        return;
    } else {
        for(int i = 0; i <= 101; i++) {
            for(int j = 0; j <= 101; j++) {
                if(matrix[i][j] == matrix[x][y]) {
                    if(i != x && j != y) {
                        left(i, j - 1, count, endX, endY);
                        break;
                    }
                }
            }
        }
    }
}

void solve(int num) {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(matrix[i][j] == 0) {
                up(i - 1, j, 0, i, j);
                down(i + 1, j, 0, i, j);
                right(i, j + 1, 0, i, j);
                left(i, j - 1, 0, i, j);
            }
        }
    }
    if(maxNum == 0) maxNum = 1;
    cout << "#" << num << " " << maxNum - 1 << endl;
    maxNum = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        cin >> N;
        initMatrix();
//        printBoard();
        solve(i + 1);
    }
    
}
