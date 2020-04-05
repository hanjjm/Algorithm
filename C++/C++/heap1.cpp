#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int len = scoville.size();
    for(int i = 0; i < len; i++) pq.push(scoville[i]);
    if(pq.size() == 1 && K <= pq.top()) return 1;
    else if(pq.size() == 1 && K > pq.top()) return -1;
    int index = 0;
    while(pq.top() < K && pq.size() >= 2) {
        if(index > 1000000) return -1;
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        pq.push(first + 2 * second);
        if(pq.size() == 1 && K <= pq.top()) return 1;
        else if(pq.size() == 1 && K > pq.top()) return -1;
        answer++;
        index++;
    }
    
    return answer;
}

