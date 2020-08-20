#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    int wordSize = words.size();
    for(int i = 0; i < wordSize; i++) {
        if(i == 0) s.insert(words[i]);
        if(i != 0 && words[i - 1][words[i - 1].length() - 1] != words[i][0]) {
            if((i + 1) % n == 0) {
                answer.push_back(n);
                answer.push_back((i + 1) / n);
            } else {
                answer.push_back((i + 1) % n);
                answer.push_back((i + 1) / n + 1);
            }
            break; // 끝
        }
        if(i != 0 && words[i - 1][words[i - 1].length() - 1] == words[i][0]) {
            int temp = s.size();
            s.insert(words[i]);
            if(temp == s.size()) {
                if((i + 1) % n == 0) {
                answer.push_back(n);
                answer.push_back((i + 1) / n);
            } else {
                answer.push_back((i + 1) % n);
                answer.push_back((i + 1) / n + 1);
            }
                break; // 끝
            }
        }
    }
    if(answer.size() == 0) {
        for(int i = 0; i < 2; i++) answer.push_back(0);
    }
    return answer;
}
