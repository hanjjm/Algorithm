//
//  p1753.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/10.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> vec(20001);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int V, E, start;
    cin >> V >> E >> start;
    
    for(int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        
        vec[from].push_back(make_pair(to, weight));
    }
    
    int dist[20001];
    for(int i = 0; i < V + 1; i++) dist[i] = 987654321;
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();
        
        for(int i = 0; i < vec[currentNode].size(); i++) {
            int nextNode = vec[currentNode][i].first;
            int nextCost = vec[currentNode][i].second;
            
            if(dist[nextNode] > cost + nextCost) {
                dist[nextNode] = cost + nextCost;
                pq.push(make_pair(-dist[nextNode], nextNode));
            }
        }
    }
    
    for(int i = 1; i <= V; i++) {
        if(dist[i] == 987654321) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    
    return 0;
}
