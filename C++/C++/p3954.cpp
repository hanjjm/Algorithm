//
//  p3954.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/17.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;

    int memorySize, codeLength, inputSize;
    string code, text;
    for(int i = 0; i < testCase; i++) {
        cin >> memorySize >> codeLength >> inputSize;
        cin >> code >> text;

        int index = 0;
        for(int j = 0; j < codeLength; j++) {
            if(code[j] == '+') {
                
            } else if(code[j] == '-') {

            } else if(code[j] == '<') {

            } else if(code[j] == '>') {

            } else if(code[j] == '[') {

            } else if(code[j] == ']') {

            }
        }

    }
}
