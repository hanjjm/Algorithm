//
//  p1992.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/23.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int pattern[64][64];
int testCase;

void divide(int where, int a, int b, int c, int d) {
    int flag = 0;
    int index = pattern[a][c];
    for(int i = a; i < b; i++) {
        for(int j = c; j < d; j++) {
            if(pattern[i][j] != index) flag = 1;
        }
    }
    
    if(flag == 0 && where != testCase) {
        if(where == 0) cout << "(";
        cout << index;
        if(where == 3) cout << ")";
    } else if(flag == 0 && where == testCase) {
        cout << index;
    }
    
    if(flag == 1) {
        if(where == 0) cout << "(";
        divide(0, a, (a + b) / 2, c, (c + d) / 2);
        divide(1, a, (a + b) / 2, (c + d) / 2, d);
        divide(2, (a + b) / 2, b, c, (c + d) / 2);
        divide(3, (a + b) / 2, b, (c + d) / 2, d);
        if(where == 3) cout << ")";
    }
    
    flag = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        string eachLine;
        cin >> eachLine;
        for(int j = 0; j < testCase; j++) {
            char tempChar[1];
            tempChar[0] = eachLine[j];
            pattern[i][j] = atoi(tempChar);
        }
    }
    
    divide(testCase, 0, testCase, 0, testCase);
}
