#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long answer = 0;
    sort(times.begin(), times.end());
    unsigned long long right = times[times.size() - 1] * n;
    unsigned long long left = 1;
    answer = right;
    
    while(left <= right) {
        unsigned long long count = 0;
        unsigned long long mid = (left + right) / 2;
            
        for(int i = 0; i < times.size(); i++) {
            count += mid / times[i];
        }
        
        if(count < n) {
            left = mid + 1;
        } else {
            if(answer >= mid) answer = mid;
            right = mid - 1;
        }
        
    }
    
    return answer;
}
