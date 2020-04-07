#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0, index = 0;
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        if(dates[index] == i + 1) {
            if(index + 1 < dates.size() && stock <= dates[index + 1] - dates[index]) {
                pq.push(supplies[index]);
                stock += pq.top();
                pq.pop();
                index++;
                answer++;
            } else if(index + 1 == dates.size() && stock <= k - dates[index]) {
                while(stock <= k - dates[index]) {
                    pq.push(supplies[index]);
                    stock += pq.top();
                    pq.pop();
                    answer++;
                }
            } else {
                pq.push(supplies[index]);
                index++;
            }
        }
        stock--;
    }
    return answer;
}
