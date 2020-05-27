//
//  s4012.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/27.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int food[16][16];
int foodCase, minNum;
int arr[16], selected[16];

void inputMatrix() {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) food[i][j] = 0;
    }
    
    for(int i = 0; i < foodCase; i++) {
        for(int j = 0; j < foodCase; j++) cin >> food[i][j];
    }
}

void initCombination() {
    for(int i = 0; i < foodCase; i++) {
        arr[i] = i;
        selected[i] = 0;
    }
}

void solve() {
    int a = 0, b = 0;
    for(int i = 0; i < foodCase; i++) {
        if(selected[i] == 1) {
            for(int j = 0; j < foodCase; j++) {
                if(selected[j] == 1) a += food[arr[i]][arr[j]];
            }
        } else if(selected[i] == 0) {
            for(int j = 0; j < foodCase; j++) {
                if(selected[j] == 0) b += food[arr[i]][arr[j]];
            }
        }
    }
//    cout << "a : " << a << ", b = " << b <<endl;
    minNum = min(minNum, abs(a - b));
}

void combi(int index, int count) {
    if(count == foodCase / 2) {
        solve();
        return;
    }
    
    for(int i = index; i < foodCase; i++) {
        if(selected[i] == 1) continue;
        selected[i] = 1;
        combi(i, count + 1);
        selected[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        cin >> foodCase;
        minNum = 987654321;
        inputMatrix();
        initCombination();
        combi(0, 0);
        cout << "#" << i + 1 << " " << minNum << endl;
    }
}
