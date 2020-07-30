//
//  p1339.cpp
//  C++
//
//  Created by KimHanJu on 2020/07/30.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<string> vec;
vector<int> sortArr;
int arr[26] = {0, };

bool compare(int a, int b) {
    if(a >= b) return true;
    else return false;
}

int main() {
    int testCase, answer = 0;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        string temp;
        cin >> temp;
        vec.push_back(temp);
    }
    
    for(int i = 0; i < testCase; i++) {
        for(int j = 0; j < vec[i].length(); j++) {
            arr[int(vec[i][j]) - 65] += pow(10, vec[i].length() - 1 - j);
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(arr[i] != 0) sortArr.push_back(arr[i]);
    }
    
    sort(sortArr.begin(), sortArr.end(), compare);
    
    for(int i = 0; i < sortArr.size(); i++) answer += sortArr[i] * (9 - i);
    
    cout << answer;
    
    return 0;
}
