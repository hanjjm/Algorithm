//
//  p2908.cpp
//  C++
//
//  Created by KimHanJu on 2019/11/26.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string first, second;
    cin >> first >> second;
    reverse(first.begin(), first.end()); //이건 algorithm..?
    reverse(second.begin(), second.end());
    
    //if(atoi(first.c_str()) > atoi(second.c_str())) cout << first;
    if(stoi(first) > stoi(second)) cout << first;
    else cout << second;
}
