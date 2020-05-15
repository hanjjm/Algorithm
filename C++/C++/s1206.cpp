//
//  s1206.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int width, answer, eachCase;
    for(int i = 0; i < 10; i++) { // tc
        cin >> width;
        int building[width];
        answer = 0;
        for(int j = 0; j < width; j++) cin >> building[j];
        for(int j = 2; j < width - 2; j++) {
            eachCase = 987654321;
            for(int k = 1; k <= 2; k++) {
                eachCase = min(eachCase, building[j] - building[j + k]);
                eachCase = min(eachCase, building[j] - building[j - k]);
            }
            if(eachCase >= 0) answer += eachCase;
        }
        cout << "#" << i + 1 << " " << answer << endl;
    }
}
