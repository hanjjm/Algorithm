//
//  p17822.cpp
//  C++
//
//  Created by KimHanJu on 2020/06/03.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <deque>
using namespace std;

deque<int> deq[50];
int visited[50][50] = {0, };

int circleSize, numberCount, rotateCount;
int target[50], direction[50], rotateNumber[50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init() {
    for(int i = 0; i < 50; i++) {
        target[i] = 0; direction[i] = 0; rotateNumber[i] = 0;
    }
}

void inputCase() {
    cin >> circleSize >> numberCount >> rotateCount;
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) {
            int inputNum;
            cin >> inputNum;
            deq[i].push_back(inputNum);
        }
    }
    for(int i = 0; i < rotateCount; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        target[i] = a; direction[i] = b; rotateNumber[i] = c;
    }
}

void rotateCircle(int index) { // target의 배수의 원들을 direction 방향(0-시계/1-반시계)으로 rotateNumber만큼 회전
    int targetIndex = target[index] - 1;
    int tempTarget = targetIndex;
    int rotateDirection = direction[index];
    int rotate = rotateNumber[index];
    while(true) {
        if(rotateDirection == 1) {
            for(int j = 0; j < rotate; j++) {
                deq[targetIndex].push_back(deq[targetIndex].front());
                deq[targetIndex].pop_front();
            }
        } else if(rotateDirection == 0) {
            for(int j = 0; j < rotate; j++) {
                deq[targetIndex].push_front(deq[targetIndex].back());
                deq[targetIndex].pop_back();
            }
        }
        targetIndex += tempTarget + 1;
        if(targetIndex > circleSize - 1) break;
    }
}

void changeNumber() { // 인접한 수가 없으면 수 변형
    double allNumber = 0, count = 0;
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) {
            if(deq[i][j] != 0) {
                allNumber += deq[i][j];
                count++;
            }
        }
    }
    
    double meanNum = allNumber / count;
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) {
            if(deq[i][j] > meanNum && deq[i][j] != 0) deq[i][j] -= 1;
            else if(deq[i][j] < meanNum && deq[i][j] != 0) deq[i][j] += 1;
        }
    }
}

void deleteAdjacent() { // 인접한 수가 있다면 delete
    stack<pair<int, int>> st;
    vector<pair<int, int>> coor;
    int flag = 0;
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) visited[i][j] = 0;
    }
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) {
            if(deq[i][j] == 0) continue;
            st.push(make_pair(i, j));
            coor.push_back(make_pair(i, j));
            visited[i][j] = 1;
            while(true) {
                if(st.empty()) break;
                int x = st.top().first;
                int y = st.top().second;
                st.pop();                for(int k = 0; k < 4; k++) {
                    if(y + dy[k] >= 0 && y + dy[k] < numberCount && x + dx[k] >= 0 && x + dx[k] < circleSize) {
                        if(deq[x + dx[k]][y + dy[k]] == deq[x][y] && visited[x + dx[k]][y + dy[k]] == false) {
                            st.push(make_pair(x + dx[k], y + dy[k]));
                            coor.push_back(make_pair(x + dx[k], y + dy[k]));
                            visited[x + dx[k]][y + dy[k]] = 1;
                            flag = 1;
                        }
                    } else if(y + dy[k] < 0) {
                        if(deq[x][numberCount - 1] == deq[x][y] && visited[x][numberCount - 1] == false) {
                            st.push(make_pair(x, numberCount - 1));
                            coor.push_back(make_pair(x, numberCount - 1));
                            visited[x][numberCount - 1] = 1;
                            flag = 1;
                        }
                    } else if(y + dy[k] >= numberCount) {
                        if(deq[x][0] == deq[x][y] && visited[x][0] == false) {
                            st.push(make_pair(x, 0));
                            coor.push_back(make_pair(x, 0));
                            visited[x][0] = 1;
                            flag = 1;
                        }
                    }
                }
            }
            if(coor.size() == 1) {
                coor.clear();
                continue;
            } else if(coor.size() > 1){
                for(int k = 0; k < coor.size(); k++) {
                    deq[coor[k].first][coor[k].second] = 0;
                }
                coor.clear();
            }
        }
    }
    if(!flag) changeNumber();
}

int solve() {
    int answer = 0;
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) answer += deq[i][j];
    }
    return answer;
}

void printCircle() {
    for(int i = 0; i < circleSize; i++) {
        for(int j = 0; j < numberCount; j++) cout << deq[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    init();
    inputCase();
    for(int i = 0; i < rotateCount; i++) {
        rotateCircle(i);
        deleteAdjacent();
    }
    cout << solve() << endl;
}
