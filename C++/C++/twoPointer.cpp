#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0); answer.push_back(987654321);
    
    unordered_map<string, int> um;
    set<string> jewel;
    int len = gems.size();
    
    for(int i = 0; i < len; i++) jewel.insert(gems[i]);
    int maxSize = jewel.size();
    
    int start = 0, end = 0;
    while(true) {
        if(um.size() < maxSize && end == len) break;
        
        if(um.size() == maxSize) {
            if(um[gems[start]] >= 2) um[gems[start]]--;
            else if(um[gems[start]] == 1) um.erase(gems[start]);
            start++;
        } else if(um.size() < maxSize) {
            um[gems[end]]++;
            end++;
        }
        
        if(um.size() == maxSize) {
            if(answer[1] - answer[0] > end - start) {
                answer[1] = end;
                answer[0] = start;
            }
        }
    }
    
    answer[0]++;
    return answer;
}
