#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[52][52];
int length, alive;
int arr[13] = {0, };
int check[13] = {0, };
int chickenCount = 0;
vector<int> chickenDistance;
vector<int> chickenNum;
vector<vector<int>> chicken(14);
vector<pair<int, int>> house;
int minNum = 987654321;

void inputMatrix() {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) matrix[i][j] = 0;
    }
    int index = 1;
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            int num;
            cin >> num;
            if(num == 0) matrix[i][j] = num;
            else if(num == 1) {
                matrix[i][j] = num;
                house.push_back(make_pair(i, j));
            } else if(num == 2) {
                matrix[i][j] = num;
                chicken[index].push_back(i);
                chicken[index].push_back(j);
                index++;
            }
        }
    }
}

void getHouseCount() {
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            if(matrix[i][j] == 2) chickenCount++;
        }
    }
}

bool compare(int a, int b) {
    return a > b ? true : false;
}

void solve() {
    int answer, eachNum;
    int plus = 0;
    for(int i = 0; i < house.size(); i++) {
        eachNum = 987654321;
        answer = 987654321;
        for(int j = 0; j < chickenNum.size(); j++) {
            eachNum = abs(house[i].first - chicken[chickenNum[j]][0]) + abs(house[i].second - chicken[chickenNum[j]][1]);
            answer = min(answer, eachNum);
        }
        plus += answer;
    }
    minNum = min(minNum, plus);
}

void dfs(int index, int count) {
    if(count == alive) {
        for(int i = 0; i < chickenCount; i++) {
            if(check[i] == 1) chickenNum.push_back(arr[i]);
        }
        solve();
        chickenNum.clear();
        return;
    }
    for(int i = index; i < chickenCount; i++) {
        if(check[i] == 1) continue;
        check[i] = 1;
        dfs(i, count + 1);
        check[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> length >> alive;
    for(int i = 0; i < 13; i++) arr[i] = i + 1;
    inputMatrix();
    getHouseCount();
    dfs(0, 0);
    cout << minNum << endl;
}

//void solve() { // bfs는 시간초과. 오바해서 거리 구하는데 bfs 돌리지 말자~
//    int eachNum;
//    answer = 0;
//    for(int i = 1; i <= length; i++) {
//        for(int j = 1; j <= length; j++) {
//            if(matrix[i][j] == 1) {
//                chickenDistance.clear();
//                resetVisited();
//                queue<pair<int, int>> q;
//                q.push(make_pair(i, j));
//                visited[i][j] = 0;
//                eachNum = 987654321;
//                int chicken = 0;
//                while(true) {
//                    int frontX = q.front().first, frontY = q.front().second;
//                    q.pop();
//
//                    for(int k = 0; k < 4; k++) {
//                        if(visited[frontX + dx[k]][frontY + dy[k]] == -1) {
//                            q.push(make_pair(frontX + dx[k], frontY + dy[k]));
//                            visited[frontX + dx[k]][frontY + dy[k]] = visited[frontX][frontY] + 1;
//                            for(int l = 0; l < chickenNum.size(); l++) {
//                                if(matrix[frontX + dx[k]][frontY + dy[k]].second == chickenNum[l]) {
//                                    eachNum = min(eachNum, visited[frontX + dx[k]][frontY + dy[k]]);
//                                    chicken++;
////                                    cout << chicken << endl;
//                                }
//                            }
//                        }
//                    }
//                    if(chicken == alive) {
//                        answer += eachNum;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//    minNum = min(minNum, answer);
//}
