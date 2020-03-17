//
//  p12865.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

// 아직 헷갈림!

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K; //물품의 수, 버틸 수 있는 무게
    cin >> N >> K;
    
    int DP[K + 1];
    pair<int, int> item[N];
    
    for(int i = 0; i < N; i++) {
        cin >> item[i].first >> item[i].second;
    }
    
    for(int i = 0; i < K + 1; i++) DP[i] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = K; j >= 1; j--) {
            if(item[i].first <= j) DP[j] = max(DP[j], DP[j - item[i].first] + item[i].second);
        }
    }
    
    if(K == 0) cout << "0" << endl;
    else cout << DP[K] << endl;
}
