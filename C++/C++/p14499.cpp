//
//  p14499.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/01.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    int matrix[N][M];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cin >> matrix[i][j];
    }
//    cout << endl;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) cout << matrix[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
    int move = 0;
    int dice[6] = {0, };
    while(K) {
        cin >> move;
        int a = dice[0], b = dice[1], c = dice[2], d = dice[3], e = dice[4], f = dice[5];
//        cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
        if(move == 1) {
            if(y + 1 <= M - 1) {
                y += 1;
                dice[0] = f; dice[1] = b;
                dice[2] = e; dice[3] = d;
                dice[4] = a; dice[5] = c;
                
                if(matrix[x][y] != 0) {
                    dice[0] = matrix[x][y];
                    matrix[x][y] = 0;
                } else matrix[x][y] = dice[0];
                cout << dice[2] << endl;
            }
        } else if(move == 2) {
            if(y - 1 >= 0) {
                y -= 1;
                dice[0] = e; dice[1] = b;
                dice[2] = f; dice[3] = d;
                dice[4] = c; dice[5] = a;
                
                if(matrix[x][y] != 0) {
                    dice[0] = matrix[x][y];
                    matrix[x][y] = 0;
                } else matrix[x][y] = dice[0];
                cout << dice[2] << endl;
            }
        } else if(move == 3) {
            if(x - 1 >= 0) {
                x -= 1;
                dice[0] = d; dice[1] = a;
                dice[2] = b; dice[3] = c;
                dice[4] = e; dice[5] = f;
                
                if(matrix[x][y] != 0) {
                    dice[0] = matrix[x][y];
                    matrix[x][y] = 0;
                } else matrix[x][y] = dice[0];
                cout << dice[2] << endl;
            }
        } else if(move == 4) {
            if(x + 1 <= N - 1) {
                x += 1;
                dice[0] = b; dice[1] = c;
                dice[2] = d; dice[3] = a;
                dice[4] = e; dice[5] = f;
                
                if(matrix[x][y] != 0) {
                    dice[0] = matrix[x][y];
                    matrix[x][y] = 0;
                } else matrix[x][y] = dice[0];
                cout << dice[2] << endl;
            }
        }
        
        K--;
    }
}
