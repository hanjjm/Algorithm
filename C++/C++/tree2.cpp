#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 987654321, compress = 1, index = 0, count = 0;
    string copy = "";
    
    if(s.length() == 1 || s.length() == 2) return s.length();
    
    while(true) {
        if(index + compress >= s.length()) {
            if(count != 0) copy += to_string(count + 1);
            copy += s.substr(index, compress);
            
            int len = copy.length();
            answer = min(len, answer);
            
            copy = ""; count = 0; index = 0;
            compress++;
            if(compress == s.length() / 2 + 1) break;
        }
        
        if(s.substr(index, compress) == s.substr(index + compress, compress)) count++;
        else {
            if(count != 0) copy += to_string(count + 1);
            copy += s.substr(index, compress);
            count = 0;
        }
        index += compress;
    }
    
    return answer;
}


/*
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
        
        // for(int j = 0; j < arrSize; j++) cout << arr[j] << " ";
        // cout << endl;
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
        // cout << result << endl;
        answer = min(answer, compare);
    }
    if(len == 1 || len == 2) answer = len;
    
    return answer;
}
*/
