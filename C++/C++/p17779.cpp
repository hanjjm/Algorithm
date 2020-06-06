//
//  p17779.cpp
//  C++
//
//  Created by KimHanJu on 2020/06/05.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int matrix[22][22] = {0, };
int N;

void input() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> matrix[i][j];
    }
}

void printM() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cout << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}

//void solve() {
//    for(int x = 1; x <= N - 2; x++) {
//        for(int y = 2; y <= N - 1; y++) {
//            for(int d1 = 1; x + d1 <= N - 2; d1++) {
//                for(int d2 = 1; d2 <= N - 2; d2++) {
//
//                }
//            }
//
//        }
//    }
//}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    input();
    solve();
}
