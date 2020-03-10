//
//  p11650.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    pair<int, int> point[num];
    for(int i = 0; i < num; i++) scanf("%d %d", &point[i].first, &point[i].second);
    
    sort(point, point + num);
    for(int i = 0; i < num; i++) printf("%d %d\n", point[i].first, point[i].second);
}

/* 시간초과
int main() {
    int num;
    cin >> num;
    int point[num][2];
    
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < 2; j++) point[i][j] = 0;
    }
    
    for(int i = 0; i < num; i++) cin >> point[i][0] >> point[i][1];
    for(int i = 0; i < num - 1; i++) {
        for(int j = i + 1; j < num; j++) {
            if(point[i][0] > point[j][0]) {
                swap(point[i][0], point[j][0]);
                swap(point[i][1], point[j][1]);
            }
        }
    }
    
    for(int i = 0; i < num - 1; i++) {
        for(int j = i + 1; point[i][0] == point[j][0]; j++) {
            if(point[i][1] > point[j][1]) swap(point[i][1], point[j][1]);
        }
    }
    
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < 2; j++) cout << point[i][j] << " ";
        cout << endl;
    }
}
*/
