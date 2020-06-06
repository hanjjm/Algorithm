#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int len, M, virusCount = 0, timer, minNum = 987654321;
vector<vector<int>> virus(11);
vector<pair<int, int>> nowVirus;
int matrix[52][52] ;
int visited[52][52];
int arr[10], check[10] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void input() {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) matrix[i][j] = -9;
    }
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 1) visited[i][j] = 1;
            else if(matrix[i][j] == 2) {
                virusCount++;
                virus[virusCount].push_back(i);
                virus[virusCount].push_back(j);
                visited[i][j] = 1;
            }
        }
    }
}

void combinationInit() {
    for(int i = 0; i < 10; i++) arr[i] = i + 1;
}

void visitedInit() {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            if(matrix[i][j] == 1) visited[i][j] = 1;
            else if(matrix[i][j] == 2) visited[i][j] = 1;
            else if(matrix[i][j] == 0) visited[i][j] = 0;
        }
    }
}

bool fullCheck() {
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) {
            if(visited[i][j] == 0) return false;
        }
    }
    return true;
}

void printVisited() {
    cout << endl;
    for(int i = 1; i <= len; i++) {
        for(int j = 1; j <= len; j++) cout << visited[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void bfs() {
    visitedInit();
    int flag = 0;
    timer = 0;
    while(true) {
        if(fullCheck()) break;
        int virusSize = nowVirus.size();
        for(int i = 0; i < virusSize; i++) {
            int frontX = nowVirus[i].first;
            int frontY = nowVirus[i].second;
            for(int j = 0; j < 4; j++) {
                if(matrix[frontX + dx[j]][frontY + dy[j]] == 0 && visited[frontX + dx[j]][frontY + dy[j]] == 0) {
                    visited[frontX + dx[j]][frontY + dy[j]] = 1;
                    nowVirus.push_back(make_pair(frontX + dx[j], frontY + dy[j]));
                } else if(matrix[frontX + dx[j]][frontY + dy[j]] == 2 && visited[frontX + dx[j]][frontY + dy[j]] == 1) {
                    visited[frontX + dx[j]][frontY + dy[j]] = 2;
                    nowVirus.push_back(make_pair(frontX + dx[j], frontY + dy[j]));
                }
            }
        }
        for(int i = 0; i < virusSize; i++) nowVirus.erase(nowVirus.begin() + 0);
        timer++;
        if(timer > 3000) { // 더 최적의 조건이 있을 것.
            flag = 1;
            break;
        }
    }
//    printVisited();
    if(!flag) minNum = min(minNum, timer);
}

void dfs(int dex, int count) {
    if(count == M) {
        nowVirus.clear();
        for(int i = 0; i < 10; i++) {
            if(check[i] == true) {
                nowVirus.push_back(make_pair(virus[arr[i]][0], virus[arr[i]][1]));
                visited[virus[arr[i]][0]][virus[arr[i]][1]] = 2;
            }
        }
        bfs();
        return;
    }
    
    for(int i = dex; i < virusCount; i++) {
        if(check[i] == true) continue;
        check[i] = true;
        dfs(i, count + 1);
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> len >> M;
    input();
    combinationInit();
    dfs(0, 0);
    if(minNum != 987654321) cout << minNum << endl;
    else cout << -1 << endl;
}
