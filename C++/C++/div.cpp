#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string translate(int div, int number) {
    char intToChar[16] = {'0','1','2','3','4','5','6','7',
                          '8','9','A','B','C','D','E','F'};
    string str;
    while(number / div > 0) { // number -> 수, div -> div진법
        str = intToChar[number % div] + str;
        number /= div;
    }
    str = intToChar[number % div] + str;
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "", str = "";
    int index = 1;
    
    for(int number = 0; number < 100000; number++) {
        str += translate(n, number);
        if(str.length() >= 100000) break;
    }
    
    for(int i = 0; i < t; i++) answer += str[p + (m * i) - 1];
    
    return answer;
}
