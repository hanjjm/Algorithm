//
//  p11047.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/24.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int coinNum, targetPrice;
    cin >> coinNum >> targetPrice;
    int coin[coinNum];
    for(int i = 0; i < coinNum; i++) cin >> coin[i];
    
    int count = 0;
    for(int i = coinNum - 1; i >= 0; i--) {
        while(targetPrice >= coin[i]) {
            targetPrice -= coin[i];
            count++;
        }
    }
    cout << count;
}
