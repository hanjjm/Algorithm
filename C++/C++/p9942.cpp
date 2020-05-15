//
//  p9942.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec(100);
vector<int> eachCase;
int arr[10], sel[10];

void init() {
    for(int i = 0; i < 10; i++) {
        arr[i] = i + 1;
        sel[i] = false;
    }
    vec.clear();
    eachCase.clear();
}

void permutation(int length, int target, int count) {
    if(count == length) {
        for(int i = 0; i < 100; i++) {
            if(vec[i].size() == 0) {
                for(int j = 0; j < eachCase.size(); j++) {
                    vec[i].push_back(eachCase[j]);
                }
                break;
            }
        }
    }
    
    for(int i = 0; i < length; i++) {
        if(sel[i] == true) continue;
        sel[i] = true;
        eachCase.push_back(arr[i]);
        permutation(length, target, count + 1);
        sel[i] = false;
        eachCase.pop_back();
    }
}

int solve(int length, int target) {
    int answer = 0;
    int len = 0;
    
    for(int i = 0; i < 100; i++) {
        if(vec[i].size() == 0) {
            len = i;
            break;
        }
        if(i == 98) len = 100;
    }
    
//    cout << len << endl;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int maxNum = 0;
            for(int k = 0; k < length; k++) {
                maxNum += max(vec[i][k], vec[j][k]);
//                cout << endl << "A : " << vec[i][k] << ", B : " << vec[j][k];
            }
//            cout << endl << "합 : " << maxNum << endl;
            if(maxNum >= target) answer++;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        init();
        int length, target;
        cin >> length >> target;
        permutation(length, target, 0);
        cout << "#" << i + 1 << " " << solve(length, target) << endl;;
    }
}
