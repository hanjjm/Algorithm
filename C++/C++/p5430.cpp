//
//  p5430.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//`

#include <iostream>
#include <deque>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        string function;
        cin >> function;
        int size;
        cin >> size;
        int RCount = 0, flag = 0;
        
        deque<int> deque;
        string myArray;
        cin >> myArray;
        int index = 0, number = 0;
        for(int i = 1; i < myArray.size(); i++) { // 숫자만 deque에 넣기.
            if(myArray[i] != ',' && myArray[i] != '[' && myArray[i] != ']') {
                char temp[1] = "";
                temp[0] = myArray[i];
                number *= 10;
                number += atoi(temp);
                index++;
            } else {
                if(number != 0) {
                    deque.push_back(number);
                    index = 0;
                    number = 0;
                }
            }
        }
        
        for(int i = 0; i < function.size(); i++) {
            if(function[i] == 'R') {
                RCount++;
            }
            else {
                if(deque.empty()) {
                    flag = 1;
                    break;
                } else {
                    if(RCount % 2 == 0) deque.pop_front();
                    else deque.pop_back();
                }
            }
        }
        
        if(flag == 1) cout << "error" << endl;
        else {
            if(RCount % 2 != 0) {
                cout << "[";
                if(deque.size() != 0) {
                    int dequeSize = deque.size() - 1;
                    if(dequeSize != 0) {
                        for(int i = dequeSize; i > 0; i--) cout << deque[i] << ",";
                    }
                    cout << deque[0] << "]" << endl;
                } else cout << "]" << endl;
            } else {
                cout << "[";
                if(deque.size() != 0) {
                    int dequeSize = deque.size() - 1;
                    if(dequeSize != 0) {
                        for(int i = 0; i < deque.size() - 1; i++) cout << deque[i] << ",";
                    }
                    cout << deque[deque.size() - 1] << "]" << endl;
                } else cout << "]" << endl;
            }/*
            cout << "[";
            while(!deque.empty()) {
                if(RCount % 2 != 0) {
                    auto dex = deque.back();
                    cout << dex;
                    deque.pop_back();
                } else {
                    auto dex = deque.front();
                    cout << dex;
                    deque.pop_front();
                }
                if(!deque.empty()) cout << ",";
            }
            cout << "]" << endl;;*/
        }
    }
}

