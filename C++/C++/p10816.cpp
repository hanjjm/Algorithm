//
//  p10816.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/25.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int card[500000];
int target[500000];
int result[500000];

void BS(int target, int cardNum) { //처음과 같은 방법으로 하면 67%에서 시간초과
//    if(left > right) return;
//    else {
//        int mid = (left + right) / 2;
//        if(card[mid] == target) {
//            result[where]++;
//            int index = 1;
//            while(card[mid + index] == card[mid]) {
//                result[where]++;
//                index++;
//            }
//            index = 1;
//            while(card[mid - index] == card[mid]) {
//                result[where]++;
//                index++;
//            }
//        }
//        else if(card[mid] < target) BS(target, mid + 1, right, where);
//        else BS(target, left, mid - 1, where);
//    }
    cout << upper_bound(card, card + cardNum, target) - lower_bound(card, card + cardNum, target) << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int M, K;
    cin >> M;
    for(int i = 0; i < M; i++) cin >> card[i];
    cin >> K;
    sort(card, card + M);
    for(int i = 0; i < K; i++) cin >> target[i];
    for(int i = 0; i < K; i++) BS(target[i], M);
}
