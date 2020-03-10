//
//  p7568.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;
    int person[num][2];
    int result[num];
    
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 2; j++) person[i][j] = 0;
    }
    for(int i = 0; i < num; i++) cin >> person[i][0] >> person[i][1];
    for(int i = 0; i < num; i++) {
        int rank = 1;
        for(int j = 0; j < num; j++) {
            if(person[i][0] < person[j][0] && person[i][1] < person[j][1]) rank++;
        }
        result[i] = rank;
    }
    
    for(int i = 0; i < num; i++) cout << result[i] << " ";
}
