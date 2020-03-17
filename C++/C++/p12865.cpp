//
//  p12865.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

// 다른문제 풀고 넘어오자!

#include <iostream>
#include <algorithm>
using namespace std;

int DP[100000];
int W[100];
int V[100];

void init(int w, int v, int n) {
    W[n] = w;
    V[n] = v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K; //물품의 수, 버틸 수 있는 무게
    cin >> N >> K;
    
    for(int i = 0; i < 100; i++) {
        W[i] = 0;
        V[i] = 0;
    }
    
    for(int i = 0; i < N; i++) {
        int W, V; //무게, 가치
        cin >> W >> V;
        init(W, V, i);
    }
    
    DP[0] = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            if(W[j] <= i) DP[i] = max(DP[i], DP[i - W[j]] + V[j]);
        }
    }
    
    if(K == 0) cout << "0" << endl;
    else cout << DP[K - 1] << endl;
}
