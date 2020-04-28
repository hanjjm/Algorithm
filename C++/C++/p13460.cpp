//
//  p13460.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/27.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
char matrix[10][10];
int answer = 11;
void init(int line, int row) {
    for(int i = 0; i < line; i++) {
        string eachLine;
        cin >> eachLine;
        for(int k = 0; k < row; k++) matrix[i][k] = eachLine[k];
    }
}

void printMatrix(int line, int row) {
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < row; j++) cout << matrix[i][j];
        cout << endl;
    }
}

pair<int, int> searchR(int line, int row) {
    pair<int, int> coordinate;
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < row; j++) {
            if(matrix[i][j] == 'R') coordinate = make_pair(i, j);
        }
    }
    return coordinate;
}

pair<int, int> searchB(int line, int row) {
    pair<int, int> coordinate;
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < row; j++) {
            if(matrix[i][j] == 'R') coordinate = make_pair(i, j);
        }
    }
    return coordinate;
}

void rotate(int line, int row, int direction, int turn, char copyM[10][10]) {
    //cout << turn << endl;
    int flag = 11;
    pair<int, int> R = searchR(line, row);
    pair<int, int> B = searchB(line, row);
    while(flag) {
        if(direction == 0) { // 왼쪽
            copyM[R.first][R.second] = '.';
            copyM[B.first][B.second] = '.';
            while(flag) {
                if(R.second < B.second) {
                    if(copyM[R.first][R.second - 1] == '.') R.second--;
                    else if(copyM[R.first][R.second - 1] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second - 1] == 'O') {
                        answer = min(answer, turn + 1);
                        //cout << answer << endl;
                        turn = 10;
                    }
                    if(copyM[B.first][B.second - 1] == '.') B.second--;
                    else if(copyM[B.first][B.second - 1] == '#') copyM[R.first][R.second] = 'B';
                } else {
                    if(copyM[B.first][B.second - 1] == '.') B.second--;
                    else if(copyM[B.first][B.second - 1] == '#') copyM[R.first][R.second] = 'B';
                    else if(copyM[B.first][B.second - 1] == 'O') //answer = -1;
                    if(copyM[R.first][R.second - 1] == '.') R.second--;
                    else if(copyM[R.first][R.second - 1] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second - 1] == 'O') {
                        answer = min(answer, turn + 1);
                        //cout << answer << endl;
                        turn = 10;
                    }
                    
                }
                flag--;
            }
            if(turn < 10) {
                for(int i = 0; i < 4; i++) rotate(line, row, i, turn + 1, copyM);
            }
        } else if(direction == 1) { // 오른쪽
            copyM[R.first][R.second] = '.';
            copyM[B.first][B.second] = '.';
            while(flag) {
                if(R.second > B.second) {
                    if(copyM[R.first][R.second + 1] == '.') R.second++;
                    else if(copyM[R.first][R.second + 1] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second - 1] == 'O') {
                        answer = min(answer, turn + 1);
                        turn = 10;
                        //cout << answer << endl;
                    }
                    if(copyM[B.first][B.second + 1] == '.') B.second++;
                    else if(copyM[B.first][B.second + 1] == '#') copyM[R.first][R.second] = 'B';
                } else {
                    if(copyM[B.first][B.second + 1] == '.') B.second++;
                    else if(copyM[B.first][B.second + 1] == '#') copyM[R.first][R.second] = 'B';
                    else if(copyM[B.first][B.second + 1] == 'O') //answer = -1;
                    if(copyM[R.first][R.second + 1] == '.') R.second++;
                    else if(copyM[R.first][R.second + 1] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second + 1] == 'O') {
                        answer = min(answer, turn + 1);
                        //cout << answer << endl;
                        turn = 10;
                    }
                }
                flag--;
            }
            if(turn < 10) {
                for(int i = 0; i < 4; i++) rotate(line, row, i, turn + 1, copyM);
            }
        } else if(direction == 2) { // 위
            copyM[R.first][R.second] = '.';
            copyM[B.first][B.second] = '.';
            while(flag) {
                if(R.second < B.second) {
                    if(copyM[R.first - 1][R.second] == '.') R.second--;
                    else if(copyM[R.first - 1][R.second] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second - 1] == 'O') {
                        answer = min(answer, turn + 1);
                        turn = 10;
                        //cout << answer << endl;
                    }
                    if(copyM[B.first - 1][B.second] == '.') B.second--;
                    else if(copyM[B.first - 1][B.second] == '#') copyM[R.first][R.second] = 'B';
                } else {
                    if(copyM[B.first - 1][B.second] == '.') B.second--;
                    else if(copyM[B.first - 1][B.second] == '#') copyM[R.first][R.second] = 'B';
                    else if(copyM[B.first - 1][B.second] == 'O') //answer = -1;
                    if(copyM[R.first - 1][R.second] == '.') R.second--;
                    else if(copyM[R.first - 1][R.second] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first - 1][R.second] == 'O') {
                        answer = min(answer, turn + 1);
                        //cout << answer << endl;
                        turn = 10;
                    }
                }
                flag--;
            }
            if(turn < 10) {
                for(int i = 0; i < 4; i++) rotate(line, row, i, turn + 1, copyM);
            }
        } else if(direction == 3) { // 아래
            copyM[R.first][R.second] = '.';
            copyM[B.first][B.second] = '.';
            while(flag) {
                if(R.second > B.second) {
                    if(copyM[R.first + 1][R.second] == '.') R.second++;
                    else if(copyM[R.first + 1][R.second] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first][R.second - 1] == 'O') {
                        answer = min(answer, turn + 1);
                        turn = 10;
                        //cout << answer << endl;
                    }
                    if(copyM[B.first + 1][B.second] == '.') B.second++;
                    else if(copyM[B.first + 1][B.second] == '#') copyM[R.first][R.second] = 'B';
                } else {
                    if(copyM[B.first + 1][B.second] == '.') B.second++;
                    else if(copyM[B.first + 1][B.second] == '#') copyM[R.first][R.second] = 'B';
                    else if(copyM[B.first + 1][B.second] == 'O') //answer = -1;
                    if(copyM[R.first + 1][R.second] == '.') R.second++;
                    else if(copyM[R.first + 1][R.second] == '#') copyM[R.first][R.second] = 'R';
                    else if(copyM[R.first + 1][R.second] == 'O') {
                        answer = min(answer, turn + 1);
                        //cout << answer << endl;
                        turn = 10;
                    }
                }
                flag--;
            }
            if(turn < 10) {
                for(int i = 0; i < 4; i++) rotate(line, row, i, turn + 1, copyM);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int line, row;
    cin >> line >> row;
    init(line, row);
    char copyM[10][10];
    
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < row; j++) copyM[i][j] = matrix[i][j];
    }
    
    for(int i = 0; i < 4; i++) rotate(line, row, i, 0, copyM);
    
    cout << answer;
}
