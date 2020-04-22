//
//  p17136.cpp
//  C++
//
//  Created by KimHanJu on 2020/04/22.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

int answer[6] = {0, 0, 0, 0, 0, 0};
int matrix[15][15];


#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) matrix[i][j] = 0;
    }
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) cin >> matrix[i][j];
    }
    
    
    int size = 5, check = 0, check2 = 0, allIn = 0;
    while(size) {
        allIn = 0;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                check = 0;
                if(matrix[i][j] == 1) {
                    check2 = 0;
                    for(int k = 0; k < size; k++) {
                        for(int l = 0; l < size; l++) {
                            if(!matrix[i + k][j + l]) {
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
                                matrix[i + k][j + l] = 0;
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
            if(matrix[i][j]) num = -1;
        }
    }
    
    cout << num;
}
