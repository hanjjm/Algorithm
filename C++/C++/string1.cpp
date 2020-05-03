#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 987654321;
    string copyS;
    int len = s.length(), maxLen = len / 2;
    
    for(int i = 1; i <= maxLen; i++) {
        copyS = s;
        int arrSize = len / i;
        string arr[arrSize];
        for(int j = 0; j < arrSize; j++) arr[j] = "";
        int index = 0;
        
        for(int j = 0; j < arrSize; j++) {
            for(int k = index; k < index + i; k++) arr[j] += copyS[k];
            index += i;
        }
        
        string result = "";
        int check = 0;
        for(int j = 0; j < arrSize - 1; j++) {
            if(j == arrSize - 2) {
                if(arr[j] == arr[j + 1]) result += to_string(check + 2) + arr[j];
                else {
                    if(check != 0) result += to_string(check + 1) + arr[j] + arr[j + 1];
                    else result += arr[j] + arr[j + 1];
                }
                break;
            }
            if(arr[j] == arr[j + 1]) check++;
            else {
                if(check != 0) result += to_string(check + 1) + arr[j];
                else result += arr[j];
                check = 0;
            }
        }
        result += copyS.substr(arrSize * i, len - arrSize * i);
        int compare = result.length();
        answer = min(answer, compare);
    }
    if(len == 1 || len == 2) answer = len;
    
    return answer;
}
