// https://velog.io/@skyepodium/programmers-섬연결하기 참고
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100] = {0, };

bool compare(vector<int> a, vector<int> b) { // 간선의 가중치로 오름차순 정렬
    if(a[2] < b[2]) return true;
    else return false;
}

int findParent(int node) {
    // 만약 부모 노드가 자기 자신이라면, 그것이 최상위 노드
    if(parent[node] == node) return node;
    // 아니라면, 최상위 노드를 찾아준다.
    else return parent[node] = findParent(parent[node]);
}

// Kruskal Algorithm
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    for(int i = 0; i < 100; i++) parent[i] = i; // 처음은 자기 자신이 부모로 설정.
    
    for(int i = 0; i < costs.size(); i++) {
        int start = findParent(costs[i][0]);
        int end = findParent(costs[i][1]);
        int cost = costs[i][2];
        
        if(start != end) { // 아직 연결이 되어 있지 않은 상태면
            parent[start] = end;
            answer += cost;
        }
    }
    
    return answer;
}
