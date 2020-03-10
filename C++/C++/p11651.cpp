//
//  p11651.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> one, pair<int, int> two) {
    if(one.second == two.second) return one.first < two.first;
    else return one.second < two.second;
}

int main() {
    int num;
    scanf("%d", &num);
    pair<int, int> point[num];
    for(int i = 0; i < num; i++) scanf("%d %d", &point[i].first, &point[i].second);
    
    sort(point, point + num, compare);
    for(int i = 0; i < num; i++) printf("%d %d\n", point[i].first, point[i].second);
}
