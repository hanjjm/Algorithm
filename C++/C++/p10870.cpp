//
//  p10870.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int fibonacci(int num) {
    if(num == 0) return 0;
    else if(num == 1) return 1;
    else return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    int num;
    cin >> num;
    cout << fibonacci(num);
}
