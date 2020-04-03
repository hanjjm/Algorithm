#include <string>
#include <deque>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<pair<int, int>> deq;
    int length = progresses.size();
    for(int i = 0; i < length; i++) {
        deq.push_back(make_pair(progresses[i], speeds[i]));
    }
    
    while(!deq.empty()) {
        length = deq.size();
        for(int i = 0; i < length; i++) deq[i].first += deq[i].second;
        int work = 0;
        while(true) {
            if(deq.empty()) break;
            else {
                if(deq.front().first >= 100) {
                    deq.pop_front();
                    work++;
                } else break;
            }
        }
        
        if(work != 0) answer.push_back(work);
    }
    
    return answer;
}
