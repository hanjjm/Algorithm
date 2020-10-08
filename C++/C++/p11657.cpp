// https://yabmoons.tistory.com/380 참고

//
//  p11657.cpp
//  C++
//
//  Created by KimHanJu on 2020/10/08.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 501

using namespace std;

int node, edge;
long long dist[MAX];
vector<pair<pair<int, int>, int>> edges;

void bellman(int start) {
    dist[start] = 0;
    
    for(int i = 0; i < node - 1; i++) { // N - 1번 탐색
        for(int j = 0; j < edges.size(); j++) {
            int from = edges[j].first.first;
            int to = edges[j].first.second;
            int w = edges[j].second;
            
            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + w) dist[to] = dist[from] + w;
        }
    }
    
    for(int i = 0; i < edges.size(); i++) {
        int from = edges[i].first.first;
        int to = edges[i].first.second;
        int w = edges[i].second;
        
        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + w) {
            cout << -1 << endl;
            return;
        }
    }
    
    for(int i = 2; i <= node; i++) {
        if(dist[i] == INF) cout << "-1" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> node >> edge;
    
    for(int i = 1; i <= node; i++) dist[i] = INF;
    for(int i = 0; i < edge; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        edges.push_back(make_pair(make_pair(from, to), w));
    }
    
    bellman(1);
    
    return 0;
}
