//
//  p17136.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/22.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

int matrix[15][15];
int copyMatrix[15][15];


#include <iostream>
using namespace std;

int solve(int size) {
    int answer[6];
    for(int i = 0; i < 6; i++) answer[i] = 0;
    int check = 0, check2 = 0, allIn = 0;
    while(size) {
        allIn = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                check = 0;
                if(copyMatrix[i][j] == 1) {
                    check2 = 0;
                    for(int k = 0; k < size; k++) {
                        for(int l = 0; l < size; l++) {
                            if(!copyMatrix[i + k][j + l]) {
                                check2 = 1;
                                break;
                            }
                            if(k == size - 1 && l == size - 1) check = 1;
                        }
                        if(check2) break;
                    }
                    if(check) {
                        for(int k = 0; k < size; k++) {
                            for(int l = 0; l < size; l++) {
                                copyMatrix[i + k][j + l] = 0;
                            }
                        }
                        answer[size]++;
                        if(answer[size] == 5) allIn = 1;
                    }
                }
                if(allIn) break;
            }
            if(allIn) break;
        }
        size--;
    }
    
    int num = 0;
    for(int i = 0; i < 6; i++) num += answer[i];
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(copyMatrix[i][j]) num = 26;
        }
    }
    return num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            copyMatrix[i][j] = 0;
            matrix[i][j] = 0;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) cin >> matrix[i][j];
    }
    
    int minNum = 26;
    for(int i = 5; i > 0; i--) {
        for(int i = 0; i < 15; i++) {
            for(int j = 0; j < 15; j++) copyMatrix[i][j] = matrix[i][j];
        }
        int eachMin = 26;
        eachMin = solve(i);
        minNum = min(minNum, eachMin);
        //cout << minNum << " ";
    }
    if(minNum == 26) minNum = -1;
    cout  << minNum;
}
