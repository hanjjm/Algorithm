//
//  p17143.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/28.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

struct eachShark {
    int x, y, velocity, direction, size;
};

int row, column, numOfSharks;
eachShark shark[10001]; // x, y, 속력, 방향, 크기, 번호
int matrix[101][101];
int answer = 0;

void init() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) matrix[i][j] = 0;
    }
    for(int i = 0; i < 10001; i++) shark[i] = {0, 0, 0, 0, 0};
}

void fishShark(int column) {
    for(int i = 1; i <= row; i++) {
        if(matrix[i][column] != 0) {
            shark[matrix[i][column]].y = 0;
            shark[matrix[i][column]].velocity = 0;
            answer += matrix[i][column];
            matrix[i][column] = 0;
            break;
        }
    }
}

void moveShark() {
    for(int i = 0; i < 10001; i++) {
        if(shark[i].y == 0) continue;
        int moveLength;
        matrix[shark[i].x][shark[i].y] = 0;
        if(shark[i].direction == 1) {
            moveLength = shark[i].x - shark[i].velocity;
            if(moveLength <= 0) {
                moveLength = abs(moveLength) + 2;
                shark[i].direction = 2;
                if(moveLength > row) {
                    moveLength = row - (moveLength - row);
                    shark[i].direction = 1;
                }
            }
            shark[i].x = moveLength;
        } else if(shark[i].direction == 2) {
            moveLength = shark[i].x + shark[i].velocity;
            if(moveLength > row) {
                moveLength = row - (moveLength - row);
                shark[i].direction = 1;
                if(moveLength <= 0) {
                    moveLength = abs(moveLength) + 2;
                    shark[i].direction = 2;
                }
            }
            shark[i].x = moveLength;
        } else if(shark[i].direction == 3) {
            moveLength = shark[i].y + shark[i].velocity;
            if(moveLength > column) {
                moveLength = column - (moveLength - column);
                shark[i].direction = 4;
                if(moveLength <= 0) {
                    moveLength = abs(moveLength) + 2;
                    shark[i].direction = 3;
                }
            }
            shark[i].y = moveLength;
        } else if(shark[i].direction == 4) {
            moveLength = shark[i].y - shark[i].velocity;
            if(moveLength <= 0) {
                moveLength = abs(moveLength) + 2;
                shark[i].direction = 3;
                if(moveLength > column) {
                    shark[i].direction = 4;
                    moveLength = column - (moveLength - column);
                }
            }
            shark[i].y = moveLength;
        }
    }
    
    for(int i = 0; i < 10001; i++) {
        if(shark[i].y == 0) continue;
        if(matrix[shark[i].x][shark[i].y] != 0) {
            if(matrix[shark[i].x][shark[i].y] < shark[i].size) {
                shark[matrix[shark[i].x][shark[i].y]].y = 0;
                shark[matrix[shark[i].x][shark[i].y]].velocity = 0;
                matrix[shark[i].x][shark[i].y] = shark[i].size;
            }
        } else matrix[shark[i].x][shark[i].y] = shark[i].size;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    init();
    
    cin >> row >> column >> numOfSharks;
    for(int i = 0; i < numOfSharks; i++) {
        int dx, dy, velo, dir, size;
        cin >> dx >> dy >> velo >> dir >> size;
        shark[size] = {dx, dy, velo, dir, size};
        matrix[shark[size].x][shark[size].y] = shark[size].size;
    }
    
    for(int i = 0; i < 10001; i++) {
        if(shark[i].y == 0) continue;
        if(shark[i].direction == 1 || shark[i].direction == 2) shark[i].velocity %= (row - 1) * 2;
        else if(shark[i].direction == 3 || shark[i].direction == 4) shark[i].velocity %= (column - 1) * 2;
    }
    
    for(int i = 1; i <= column; i++) {
        fishShark(i);
        moveShark();
    }
    cout << answer << endl;
}
