//
//  s2115.cpp
//  C++
//
//  Created by KimHanJu on 2020/06/02.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int matrix[507][507];
int row, column;
int possible[19][3][2] = {
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {-1, 1}, {-2, 1}},
    {{-1, 0}, {-1, 1}, {-1, 2}},
    {{-1, 0}, {-1, -1}, {-1, -2}},
    
    {{1, 0}, {1, 1}, {0, 1}},
    
    {{1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {-1, 1}, {-1, 2}},
    
    {{1, 0}, {1, 1}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 1}},
    {{0, 1}, {0, 2}, {-1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},
    
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {1, 1}, {1, 2}},
    
    {{1, 0}, {1, -1}, {1, -2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, -1}, {1, -1}, {2, -1}},
    {{0, -1}, {-1, -1}, {-2, -1}}
};

void inputMatrix() {
    for(int i = 0; i < 507; i++) {
        for(int j = 0; j < 507; j++) matrix[i][j] = 0;
    }
    for(int i = 3; i < 3 + row; i++) {
        for(int j = 3; j < 3 + column; j++) cin >> matrix[i][j];
    }
}

int solve() {
    int maxNum = 0;
    for(int i = 3; i < 3 + row; i++) {
        for(int j = 3; j < 3 + column; j++) {
            for(int k = 0; k < 19; k++) {
                int answer = matrix[i][j];
                for(int l = 0; l < 3; l++) {
                    answer += matrix[i + possible[k][l][0]][j + possible[k][l][1]];
                }
                maxNum = max(maxNum, answer);
            }
        }
    }
    return maxNum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> row >> column;
    inputMatrix();
    cout << solve() << endl;;
}
