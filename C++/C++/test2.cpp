//
//  test2.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/07.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int aaa(string a, string b) {
    if(a == b) return 5;
}

int main() {
    
    int b = aaa("1", "2");
    cout << b << endl;
    return 0;
}
