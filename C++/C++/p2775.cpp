//
//  p2775.cpp
//  C++
//
//  Created by KimHanJu on 2019/12/13.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    
    int room[15][14];
    
    for(int i = 0; i < 14; i++) room[0][i] = i + 1;
    for(int i = 1; i < 15; i++) {
        for(int j = 0; j < 14; j++) {
            int temp = 0;
            for(int k = 0; k <= j; k++) temp += room[i - 1][k];
            room[i][j] = temp;
        }
    }
    
    int a, b;
    while(testCase --> 0) {
        cin >> a >> b;
        cout << room[a][b - 1] << endl;
    }
}
