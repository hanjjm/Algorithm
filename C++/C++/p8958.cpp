//
//  p8958.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/21.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int testCase;
    char OX[81];
    cin >> testCase;
    while(testCase --> 0) {
        cin >> OX;
        int temp = 0, result = 0;
        int length = strlen(OX);
        for(int i = 0; i < length; i++) {
            if(OX[i] == 'O') temp++;
            else temp = 0;
            result += temp;
        }
        cout << result << endl;
    }
}
