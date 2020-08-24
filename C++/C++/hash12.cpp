#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> index;
    
    for(int i = 1; i <= 26; i++) { // 알파벳 넣기
        string temp = "";
        temp += 'A' + i - 1;
        index[temp] = i;
    }
    
    int length = msg.length();
    if(length == 1) {
        answer.push_back(index[msg]);
        return answer;
    }
    
    for(int i = 0; i < length; i++) {
        string temp = "";
        for(int j = 0; j < length; j++) {
            temp += msg[i + j];
            if(index.count(temp) == 0) {
                index[temp] = index.size() + 1;
                temp = temp.substr(0, temp.length() - 1);
                answer.push_back(index[temp]);
                i += j - 1;
                break;
            }
        }
    }
    
    return answer;
}
