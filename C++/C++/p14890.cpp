//
//  p14890.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/28.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int matrix[102][102];
int answer = 0;

void searchLine(int ladder, int num, int length) {
    int check[102] = {0, };
    for(int i = 0; i < num; i++) {
        if(matrix[num][i] - matrix[num][i + 1] == 2
           || matrix[num][i] - matrix[num][i + 1] == -2) {
            break; // 2 이상 차이나는 경우
        } else {
            
        }
        
    }
}

void searchRow(int ladder, int num) {
    int check[102] = {0, };
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) matrix[i][j] = 5;
    }
    int line, L;
    cin >> line >> L;
    
    for(int i = 0; i < line; i++) {
        for(int j = 0; j < line; j++) cin >> matrix[i][j];
    }
    
    cout << endl;
    
//    for(int i = 0; i < line; i++) {
//        for(int j = 0; j < line; j++) cout << matrix[i][j];
//        cout << endl;
//    }
    
    for(int i = 0; i < line; i++) searchLine(L, i, line);
    for(int i = 0; i < line; i++) searchRow(L, i);
    
    cout << answer;
}
