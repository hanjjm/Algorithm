//
//  p3009.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/04.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int point[4][2];
    for(int i = 0; i < 3; i++) cin >> point[i][0] >> point[i][1];
    for(int i = 0; i < 3; i++) {
        if(point[0][0] == point[1][0]) point[3][0] = point[2][0];
        else if(point[1][0] == point[2][0]) point[3][0] = point[0][0];
        else point[3][0] = point[1][0];
        
        if(point[0][1] == point[1][1]) point[3][1] = point[2][1];
        else if(point[1][1] == point[2][1]) point[3][1] = point[0][1];
        else point[3][1] = point[1][1];
    }
    cout << point[3][0] << " " << point[3][1];
}
