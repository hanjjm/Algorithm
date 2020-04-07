#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq;
    priority_queue <int, vector<int>, greater<int>> pq2;
    vector<int> answer;
    int length = operations.size();
    int index = 0, index2 = 0;
    for(int i = 0; i < length; i++) {
        if(operations[i].substr(0, 1) == "I") {
            pq.push(stoi(operations[i].substr(2, operations[i].size())));
            pq2.push(stoi(operations[i].substr(2, operations[i].size())));
            index++;
        } else if(operations[i].substr(0, 4) == "D -1") {
            index2++;
            if(index == index2) {
                for(int j = 0; j < pq.size(); j++) pq.pop();
                for(int j = 0; j < pq2.size(); j++) pq2.pop();
            }
            if(index < index2) continue;
            pq2.pop();
        } else if(operations[i].substr(0, 3) == "D 1") {
            index2++;
            if(index == index2) {
                for(int j = 0; j < pq.size(); j++) pq.pop();
                for(int j = 0; j < pq2.size(); j++) pq2.pop();
            }
            if(index < index2) continue;
            pq.pop();
        }
    }
    if(index < index2) for(int i = 0; i < 2; i++) answer.push_back(0);
    else {
        answer.push_back(pq.top());
        answer.push_back(pq2.top());
    }
    return answer;
}
