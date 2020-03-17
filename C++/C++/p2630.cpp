//
//  p2630.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/18.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int white = 0;
int blue = 0;
int paper[128][128];
int q = 0;
void divide(int a, int b, int c, int d) {
    int flag = 0;
    for(int i = a; i < b; i++) {
        for(int j = c; j < d; j++) {
            if(paper[a][c] == 0) {
                if(paper[i][j] == 1) flag = 1;
                if(i == b - 1 && j == d - 1 && flag == 0) white++;
            } else if(paper[a][c] == 1){
                if(paper[i][j] == 0) flag = 1;
                if(i == b - 1 && j == d - 1 && flag == 0) blue++;
            }
        }
    }
    
    if(flag == 1) q++;
    if(flag) {
        divide(a, (a + b) / 2, c, (c + d) / 2);
        divide((a + b) / 2, b, c, (c + d) / 2);
        divide(a, (a + b) / 2, (c + d) / 2, d);
        divide((a + b) / 2, b, (c + d) / 2, d);
    }
}

int main() {
    int length;
    cin >> length;
    
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) cin >> paper[i][j];
    }
    
    divide(0, length, 0, length);
    
    cout << white << endl << blue << endl;
}
