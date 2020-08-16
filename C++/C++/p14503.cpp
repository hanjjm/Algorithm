//
//  p14503.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/05.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

//#include <iostream>
//using namespace std;
//
//int room[52][52] = {0, };
//int direction[4] = {0, 1, 2, 3};
//int column, row;
//int x, y, dir;
//
//void inputNum() {
//    cin >> column >> row >> x >> y >> dir;
//    for(int i = 0; i < column; i++)
//        for(int j = 0; j < row; j++) cin >> room[i][j];
//}
//
//void solve(int x, int y, int dir, int flag) {
//    if(room[x][y] == 0) room[x][y] = 2; // 현재 공간 청소
//    dir++;
//    if(dir == 4) dir = 0;
//    if(dir == 0) {
//        if(room[x - 1][y] == 0) {
//            x -= 1;
//            solve(x, y, dir, flag);
//        } else if(room[x - 1][y] == 1 || room[x - 1][y] == 2) {
//            solve(x, y, dir, flag);
//        }
//    } else if(dir == 1) {
//        if(room[x][y + 1] == 0) {
//
//        }
//    } else if(dir == 2) {
//        if(room[x + 1][y] == 0) {
//
//        }
//    } else if(dir == 3) {
//        if(room[x][y - 1] == 0) {
//
//        }
//    }
//}
//
//int main() {
//    ios::sync_with_stdio();
//    cin.tie(NULL); cout.tie(NULL);
//
//    inputNum();
//    solve(x, y, direction[dir], 0);
//
//    return 0;
//}
