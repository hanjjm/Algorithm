#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int index = 0;
    while(n > 0) {
        index = n % 3;
        if(index == 0) {
            answer = "4" + answer;
            n--;
        } else answer = to_string(index) + answer;
        n /= 3;
    }
    return answer;
}
