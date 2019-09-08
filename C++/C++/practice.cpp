//
//  practice.cpp
//  C++
//
//  Created by KimHanJu on 08/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

struct Car {
    int num;
    double gas;
};

void buy(Car& pCar) {
   // cout << pCar->num;
    pCar.num = 12345;
}

int main(int argc, const char * argv[]) {
    Car car1;
    car1.num = 123;
    car1.gas = 12.34;
    buy(car1);
    cout << car1.num;
    return 0;
}
