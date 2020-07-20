#include <string>
#include <bitset>
#include <iostream>
using namespace std;

int solution(int n) {
    int oneNumber = bitset<20>(n).count();
    while(true) {
        n++;
        if(oneNumber == bitset<20>(n).count()) break;
    }
    
    return n;
}

/* 시간 초과
int solution(int n) {
    int oneNumber = 0;
    int originalN = n;
    for(int i = n; i > 0; i--) {
        if(n % 2 == 1) oneNumber++;
        n /= 2;
    }
    
    while(true) {
        originalN++;
        n = originalN;
        int oneTemp = 0;
        for(int i = n; i > 0; i--) {
            if(n % 2 == 1) oneTemp++;
            n /= 2;
        }
        if(oneTemp == oneNumber) break;
    }
    
    return originalN;
}
*/
