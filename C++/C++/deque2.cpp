#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    deque<pair<int, int>> onBridge;
    queue<int> waiting;
    int length = truck_weights.size();
    for(int i = 0; i < length; i++) waiting.push(truck_weights[i]);
    int now = waiting.front();
    waiting.pop();
    onBridge.push_back(make_pair(now, 0));
    while(!waiting.empty()) {
        if(now + waiting.front() <= weight) {
            onBridge.push_back(make_pair(waiting.front(), answer));
            now += waiting.front();
            waiting.pop();
        }
        if(waiting.empty()) break;
        else answer++;
        
        if(onBridge.front().second + bridge_length == answer) {
            now -= onBridge.front().first;
            onBridge.pop_front();
        }
    }
    
    return answer + bridge_length + 1;
}
