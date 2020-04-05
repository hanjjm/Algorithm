#include <string>
#include <deque>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    deque<int> deq;
    int len = prices.size();
    
    for(int i = 0; i < len; i++) deq.push_back(prices[i]);
    
    for(int i = 0; i < len; i++) {
        for(int j = i; j < len; j++) {
            if(deq[i] > deq[j]) {
                answer.push_back(j - i);
                break;
            } else if(j == len - 1) answer.push_back(deq.size() - i - 1);
        }
    }
    
    return answer;
}
