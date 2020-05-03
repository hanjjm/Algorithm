//
//  p17471.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/03.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int eachPlace[11];
int matrix[11][11];
int answer = 987654321;
int arr[11] = {0, };
bool select[11] = {0, };

void matrixInit(int num) {
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) matrix[i][j] = 0;
    }
    
    int adjCase, adj;
    for(int i = 1; i <= num; i++) {
        cin >> adjCase;
        for(int j = 1; j <= adjCase; j++) {
            cin >> adj;
            matrix[i][adj] = 1;
        }
    }
}

void printM(int place) {
    for(int i = 0; i < place; i++) {
        if(select[i] == true) cout << arr[i] << " ";
    }
    cout << endl;
}

void combination(int index, int count, int place) {
    if(count == 1) {
        printM(place);
        return;
    }
    for(int i = index; i < place; i++) {
        if(select[i]) continue;
        select[i] = true;
        
        combination(i, count + 1, place);
        select[i] = false;
    }
}

bool adjCheck() {
    
    
    return true;
}

void solve(int num, int place) {
    for(int i = 0; i < place; i++) arr[i] = i + 1;
    
    switch(num) {
        case 1: {
            combination(0, 0, place);
            break;
        }
        case 2: {
            answer = 2;
            break;
        }
        case 3: {
            answer = 3;
            break;
        }
        case 4: {
            answer = 4;
            break;
        }
        case 5: {
            answer = 5;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int place;
    cin >> place;
    for(int i = 1; i <= place; i++) cin >> eachPlace[i]; //각 구역 사람 초기화
    matrixInit(place);
    
    for(int i = 1; i <= place / 2; i++) solve(i / 2, i);
}
