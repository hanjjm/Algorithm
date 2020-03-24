//
//  p1920.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/24.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int A[100000];
int B[100000];

int BS(int target, int left, int right) {
    if(left > right) return 0;
    else {
        int mid = (left + right) / 2;
        if(A[mid] == target) return 1;
        else if(A[mid] < target) return BS(target, mid + 1, right);
        else return BS(target, left, mid - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for(int i = 0; i < M; i++) cin >> B[i];
    sort(A, A + N);
    for(int i = 0; i < M; i++) cout << BS(B[i], 0, N - 1) << "\n";
}
