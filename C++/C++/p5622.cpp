//
//  p5622.cpp
//  C++
//
//  Created by KimHanJu on 2019/12/12.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    char number[15];
    int time = 0;
    int result = 0;
    cin >> number;
    
    for(int i = 0; number[i] != NULL; i++) {
        if(number[i] >= 65 && number[i] <= 67) time = 3;
        else if(number[i] >= 68 && number[i] <= 70) time = 4;
        else if(number[i] >= 71 && number[i] <= 73) time = 5;
        else if(number[i] >= 74 && number[i] <= 76) time = 6;
        else if(number[i] >= 77 && number[i] <= 79) time = 7;
        else if(number[i] >= 80 && number[i] <= 83) time = 8;
        else if(number[i] >= 84 && number[i] <= 86) time = 9;
        else if(number[i] >= 87 && number[i] <= 90) time = 10;
        result += time;
        time = 0;
    }
    
    cout << result;
}
