#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    int index = 0;
    while(true) {
        int indexNum = number[index] - '0';
        for(int i = 1; i <= k; i++) {
            if(index + k >= number.length()) {
                number = number.substr(0, number.length() - 1);
                k--;
                index--;
                break;
            }
            if(indexNum < number[index + i] - '0') {
                number = number.substr(0, index) + number.substr(index + 1, number.length());
                k--;
                index--;
                break;
            }
        }
        index++;
        if(k == 0) break;
    }
    return number;
}
