#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    deque<pair<string, int>> deq; //int가 낮은것부터 정렬해야 함.
    int citySize = cities.size();
    
    if(cacheSize == 0) return 5 * citySize;
    
    for(int i = 0; i < citySize; i++) {
        for(int j = 0; j < cities[i].length(); j++) {
            if(cities[i][j] - 'A' >= 0 && cities[i][j] - 'A' <= 26) {
                cities[i][j] += 32;
            }
        }
    }
    // 시티를 deque에 있는지 확인.
    // 1. 있다면 -> 시간 초기화 2. 없다면 -> 시간 제일 큰거 빼고 넣어줌.
    // 시간 하나씩 증가
    for(int i = 0; i < citySize; i++) {
        int flag = true;
        
        for(int j = 0; j < deq.size(); j++) { // 있을 경우에
            if(deq[j].first == cities[i]) {
                deq[j].second = 0;
                answer += 1;
                flag = false;
            }
        }
        
        if(flag) { // 없다면
            if(deq.size() == cacheSize) { // 캐시 꽉찼을 때
                int maxTime = 0;
                for(int j = 0; j < deq.size(); j++) maxTime = max(maxTime, deq[j].second);
                for(int j = 0; j < deq.size(); j++) {
                    if(deq[j].second == maxTime) deq.erase(deq.begin() + j);
                }
            }
            deq.push_back(make_pair(cities[i] ,0));
            answer += 5;
        }
        for(int j = 0; j < deq.size(); j++) deq[j].second++;
    }
    
    return answer;
}
