#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0, index = 0, time = 0, endTime = 0, mean = 0;
    bool working = false;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    
    int jobsLen = jobs.size();
    while(true) {
        for(int i = 0; i < jobsLen; i++) {
            if(jobs[i][0] == time) pq.push(make_pair(jobs[i][1], jobs[i][0]));
        }
        if(!working && !pq.empty()) {
            endTime = time + pq.top().first;
            working = true;
            mean += endTime - pq.top().second;
            pq.pop();
        }
        time++;
        if(endTime == time) working = false;
        if(time == 500000) break;
    }
    return mean / jobs.size();
}
