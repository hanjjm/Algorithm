//
//  p11404.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/07.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

#define INF 987654321
int cities, buses;
int arr[101][101];

void solve() {
    for(int i = 1; i <= cities; i++) { // 거치는 vertex
        for(int j = 1; j <= cities; j++) { // from
            for(int k = 1; k <= cities; k++) { // to
                if(arr[j][i] != INF && arr[i][k] != INF) { // j -> i -> k 경로가 있을 때
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> cities >> buses;
    
    for(int i = 0; i < 101; i++) { // 1. table을 초기화한다.
        for(int j = 0; j < 101; j++) arr[i][j] = INF;
    }

    int from, to, w;
    for(int i = 0; i < buses; i++) {
        cin >> from >> to >> w;
        if(arr[from][to] > w) arr[from][to] = w; // 최솟값 update
    }
    
    solve(); // floyd-warshall
    
    for(int i = 1; i <= cities; i++) {
        for(int j = 1; j <= cities; j++) {
            if(i == j || arr[i][j] == INF) cout << "0" << " ";
            else cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
