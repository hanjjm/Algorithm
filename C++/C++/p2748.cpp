//
//  p2748.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/17.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    long long fib[n];
    
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    cout << fib[n] << endl;
}
