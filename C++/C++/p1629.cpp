//
//  p1629.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/24.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll multi(ll a, ll b, ll c) {
    if(b == 0) return 1;
    ll temp = multi(a, b / 2, c);
    temp = temp * temp % c;
    if(b % 2 == 0) return temp;
    else return temp * a % c;
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    
    ll result = multi(A, B, C);
    cout << result;
}
