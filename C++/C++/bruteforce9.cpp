#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    s = s.substr(1, s.size() - 2);
    int arr[100000] = {0, };
    string temp = "";
    for(int i = 0; i < s.length(); i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) temp += s[i];
        else {
            if(temp != "") arr[stoi(temp)]++;
            temp = "";
        }
    }
    int maxNum = 0;
    for(int i = 0; i < 100000; i++) maxNum = max(maxNum, arr[i]);
    for(int i = maxNum; i > 0; i--) {
        for(int j = 0; j < 100000; j++) {
            if(i == arr[j]) {
                answer.push_back(j);
                continue;
            }
        }
    }
    return answer;
}
