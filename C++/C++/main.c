//
//  main.c
//  C++
//
//  Created by KimHanJu on 17/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <stdio.h>

int fib(int num) {
    if (num == 0 || num == 1) return num;
    else return (fib(num - 1) + fib(num - 2));
}

int fibLoop(int num) {
    int a = 0, b = 1;
    int next = 0;
    if(num == 0 || num == 1) return num;
    else{
        for(int i = 3; i <= num; ++i) {
            next = b;
            b = a + b;
            a = next;
            return b;
        }
    }
    return 0;
}

int main() {
    printabc();
    for(int i = 0; i < 9; i++) printf("%d : %d\n", i + 1, fib(i));
    for(int i = 0; i < 9; i++) printf("%d : %d\n", i + 1, fibLoop(i));
}
