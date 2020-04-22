#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int right = 0;
    int left = 0;
    int len = name.length();
    
    for(int i = 0; i < len; i++) {
        if(name[i] - 'A' <= 13) answer += name[i] - 'A';
        else answer += 'Z' - name[i] + 1;
    }
    
    int index = 0;
    name[0] = 'A';
    while(true) {
        int temp = 0, check = 0;
        left = 0;
        right = 0;
        for(int i = index + 1;; i++) {
            if(i == len) i = 0;
            if(name[i] == 'A') right++;
            else {
                right++;
                break;
            }
            if(temp == len) {
                temp++;
                check = 1;
                break;
            }
            temp++;
        }
        if(check) break;
        for(int i = index - 1;; i--) {
            if(i == -1) i = len - 1;
            if(name[i] == 'A') left++;
            else {
                left++;
                break;
            }
            temp++;
        }
        if(left > right) {
            index += right;
            answer += right;
            if(index >= len) index -= len;
        } else if(left < right) {
            index -= left;
            answer += left;
            if(index < 0) index += len;
        } else {
            index += right;
            answer += right;
            if(index >= len) index -= len;
        }
        name[index] = 'A';
    }
    
    return answer;
}

