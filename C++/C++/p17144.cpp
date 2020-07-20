//
//  p17144.cpp
//  C++
//
//  Created by KimHanJu on 2020/06/06.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int arr[7] = {1, 2, 3, 4, 5, 6, 7};
int check[7] = {0, 0, 0, 0, 0, 0, 0};
vector<int> vec;

void Print() {
    for(int i = 0; i < 3; i++) {
        cout << check[i] << " ";
    }
//    for(int i = 0; i < 5; i++) cout << check[i] << " ";
    cout << endl;
}

void dfs(int index, int count) {
    if(count == 3) {
        Print();
        return;
    }
    
    for(int i = 0; i < 7; i++) {
//        if(check[i] == true) continue;
//        check[i] = true;
//        vec.push_back(arr[i]);
        check[count] = arr[i];
        dfs(i, count + 1);
//        vec.pop_back();
//        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    dfs(0, 0);
}
