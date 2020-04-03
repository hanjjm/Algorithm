#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> deq;
    int len = priorities.size();
    for(int i = 0; i < len; i++) deq.push_back(make_pair(priorities[i], i));
    
    while(true) {
        len = deq.size();
        
        while(true) {
            int index = 0;
            for(int i = 1; i < len; i++)
                if(deq.front().first < deq[i].first) index = 1;
            if(index) {
                deq.push_back(make_pair(deq.front().first, deq.front().second));
                deq.pop_front();
            } else break;
        }
        
        if(deq.front().second == location) break;
        else {
            deq.pop_front();
            answer++;
        }
    }
    
    return answer + 1;
}

