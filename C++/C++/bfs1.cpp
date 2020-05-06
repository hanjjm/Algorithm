#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> vec(20001);
int visited[20001] = {0, };

int bfs(int node, int count) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i = 0; i < vec[front].size(); i++) {
            if(visited[vec[front][i]] == 0) {
                q.push(vec[front][i]);
                visited[vec[front][i]] = visited[front] + 1;
            }
        }
    }
    int maxNum = 0;
    for(int i = 0; i < 20002; i++) maxNum = max(maxNum, visited[i]);
    for(int i = 0; i < 20002; i++) {
        if(visited[i] == maxNum) count++;
    }
    return count;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int len = edge.size();
    for(int i = 0; i < len; i++) {
        vec[edge[i][0]].push_back(edge[i][1]);
        vec[edge[i][1]].push_back(edge[i][0]);
    }
    answer = bfs(len, 0);
    return answer;
}
