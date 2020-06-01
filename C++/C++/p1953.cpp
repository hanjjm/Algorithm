#include <iostream>
#include <queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int matrix[52][52];
int visited[52][52];
int answer;
int row, column, manholeX, manholeY, timeSpend;

void inputMatrix() {
    for(int i = 0; i < 52; i++) {
        for(int j = 0; j < 52; j++) {
            matrix[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) cin >> matrix[i][j];
    }
}

void getAnswer() {
    answer = 0;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) {
            if(visited[i][j] >= 1) answer++;
        }
    }
}

void solve() {
    queue<pair<int, int>> q;
    q.push(make_pair(manholeX + 1, manholeY + 1));
    visited[manholeX + 1][manholeY + 1] = 1;
    while(true) {
        if(q.empty()) break;
        int frontX = q.front().first;
        int frontY = q.front().second;
        q.pop();
        // 0 = 아래, 1 = 오른쪽, 2 = 위, 3 = 왼쪽
        if(matrix[frontX][frontY] == 1) { // 4방향
            if(matrix[frontX + dx[0]][frontY + dy[0]] != 0) {
                if(visited[frontX + dx[0]][frontY + dy[0]] == 0) {
                    if(matrix[frontX + dx[0]][frontY + dy[0]] != 3 &&
                       matrix[frontX + dx[0]][frontY + dy[0]] != 5 &&
                       matrix[frontX + dx[0]][frontY + dy[0]] != 6) {
                        q.push(make_pair(frontX + dx[0], frontY + dy[0]));
                        visited[frontX + dx[0]][frontY + dy[0]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[1]][frontY + dy[1]] != 0) {
                if(visited[frontX + dx[1]][frontY + dy[1]] == 0) {
                    if(matrix[frontX + dx[1]][frontY + dy[1]] != 2 &&
                       matrix[frontX + dx[1]][frontY + dy[1]] != 4 &&
                       matrix[frontX + dx[1]][frontY + dy[1]] != 5) {
                        q.push(make_pair(frontX + dx[1], frontY + dy[1]));
                        visited[frontX + dx[1]][frontY + dy[1]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[2]][frontY + dy[2]] != 0) {
                if(visited[frontX + dx[2]][frontY + dy[2]] == 0) {
                    if(matrix[frontX + dx[2]][frontY + dy[2]] != 3 &&
                       matrix[frontX + dx[2]][frontY + dy[2]] != 4 &&
                       matrix[frontX + dx[2]][frontY + dy[2]] != 7) {
                        q.push(make_pair(frontX + dx[2], frontY + dy[2]));
                        visited[frontX + dx[2]][frontY + dy[2]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[3]][frontY + dy[3]] != 0) {
                if(visited[frontX + dx[3]][frontY + dy[3]] == 0) {
                    if(matrix[frontX + dx[3]][frontY + dy[3]] != 2 &&
                       matrix[frontX + dx[3]][frontY + dy[3]] != 6 &&
                       matrix[frontX + dx[3]][frontY + dy[3]] != 7) {
                        q.push(make_pair(frontX + dx[3], frontY + dy[3]));
                        visited[frontX + dx[3]][frontY + dy[3]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 2) { // 위 & 아래
            if(matrix[frontX + dx[2]][frontY + dy[2]] != 0) {
                if(visited[frontX + dx[2]][frontY + dy[2]] == 0) {
                    if(matrix[frontX + dx[2]][frontY + dy[2]] != 3 &&
                       matrix[frontX + dx[2]][frontY + dy[2]] != 4 &&
                       matrix[frontX + dx[2]][frontY + dy[2]] != 7) {
                        q.push(make_pair(frontX + dx[2], frontY + dy[2]));
                        visited[frontX + dx[2]][frontY + dy[2]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[0]][frontY + dy[0]] != 0) {
                if(visited[frontX + dx[0]][frontY + dy[0]] == 0) {
                    if(matrix[frontX + dx[0]][frontY + dy[0]] != 3 &&
                       matrix[frontX + dx[0]][frontY + dy[0]] != 5 &&
                       matrix[frontX + dx[0]][frontY + dy[0]] != 6) {
                        q.push(make_pair(frontX + dx[0], frontY + dy[0]));
                        visited[frontX + dx[0]][frontY + dy[0]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 3) { // 오 & 왼
            if(matrix[frontX + dx[1]][frontY + dy[1]] != 0) {
                if(visited[frontX + dx[1]][frontY + dy[1]] == 0) {
                    if(matrix[frontX + dx[1]][frontY + dy[1]] != 2 &&
                        matrix[frontX + dx[1]][frontY + dy[1]] != 4 &&
                        matrix[frontX + dx[1]][frontY + dy[1]] != 5) {
                        q.push(make_pair(frontX + dx[1], frontY + dy[1]));
                        visited[frontX + dx[1]][frontY + dy[1]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[3]][frontY + dy[3]] != 0) {
                if(visited[frontX + dx[3]][frontY + dy[3]] == 0) {
                    if(matrix[frontX + dx[3]][frontY + dy[3]] != 2 &&
                        matrix[frontX + dx[3]][frontY + dy[3]] != 6 &&
                        matrix[frontX + dx[3]][frontY + dy[3]] != 7) {
                        q.push(make_pair(frontX + dx[3], frontY + dy[3]));
                        visited[frontX + dx[3]][frontY + dy[3]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 4) { // 위 & 오
            if(matrix[frontX + dx[2]][frontY + dy[2]] != 0) {
                if(visited[frontX + dx[2]][frontY + dy[2]] == 0) {
                    if(matrix[frontX + dx[2]][frontY + dy[2]] != 3 &&
                    matrix[frontX + dx[2]][frontY + dy[2]] != 4 &&
                    matrix[frontX + dx[2]][frontY + dy[2]] != 7) {
                        q.push(make_pair(frontX + dx[2], frontY + dy[2]));
                        visited[frontX + dx[2]][frontY + dy[2]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[1]][frontY + dy[1]] != 0) {
                if(visited[frontX + dx[1]][frontY + dy[1]] == 0) {
                    if(matrix[frontX + dx[1]][frontY + dy[1]] != 2 &&
                    matrix[frontX + dx[1]][frontY + dy[1]] != 4 &&
                    matrix[frontX + dx[1]][frontY + dy[1]] != 5) {
                        q.push(make_pair(frontX + dx[1], frontY + dy[1]));
                        visited[frontX + dx[1]][frontY + dy[1]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 5) { // 오 & 아래
            if(matrix[frontX + dx[0]][frontY + dy[0]] != 0) {
                if(visited[frontX + dx[0]][frontY + dy[0]] == 0) {
                    if(matrix[frontX + dx[0]][frontY + dy[0]] != 3 &&
                    matrix[frontX + dx[0]][frontY + dy[0]] != 5 &&
                    matrix[frontX + dx[0]][frontY + dy[0]] != 6) {
                        q.push(make_pair(frontX + dx[0], frontY + dy[0]));
                        visited[frontX + dx[0]][frontY + dy[0]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[1]][frontY + dy[1]] != 0) {
                if(visited[frontX + dx[1]][frontY + dy[1]] == 0) {
                    if(matrix[frontX + dx[1]][frontY + dy[1]] != 2 &&
                    matrix[frontX + dx[1]][frontY + dy[1]] != 4 &&
                    matrix[frontX + dx[1]][frontY + dy[1]] != 5) {
                        q.push(make_pair(frontX + dx[1], frontY + dy[1]));
                        visited[frontX + dx[1]][frontY + dy[1]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 6) { // 왼 & 아래
            if(matrix[frontX + dx[3]][frontY + dy[3]] != 0) {
                if(visited[frontX + dx[3]][frontY + dy[3]] == 0) {
                    if(matrix[frontX + dx[3]][frontY + dy[3]] != 2 &&
                    matrix[frontX + dx[3]][frontY + dy[3]] != 6 &&
                    matrix[frontX + dx[3]][frontY + dy[3]] != 7) {
                        q.push(make_pair(frontX + dx[3], frontY + dy[3]));
                        visited[frontX + dx[3]][frontY + dy[3]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[0]][frontY + dy[0]] != 0) {
                if(visited[frontX + dx[0]][frontY + dy[0]] == 0) {
                    if(matrix[frontX + dx[0]][frontY + dy[0]] != 3 &&
                    matrix[frontX + dx[0]][frontY + dy[0]] != 5 &&
                    matrix[frontX + dx[0]][frontY + dy[0]] != 6) {
                        q.push(make_pair(frontX + dx[0], frontY + dy[0]));
                        visited[frontX + dx[0]][frontY + dy[0]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        } else if(matrix[frontX][frontY] == 7) { // 위 & 왼
            if(matrix[frontX + dx[2]][frontY + dy[2]] != 0) {
                if(visited[frontX + dx[2]][frontY + dy[2]] == 0) {
                    if(matrix[frontX + dx[2]][frontY + dy[2]] != 3 &&
                    matrix[frontX + dx[2]][frontY + dy[2]] != 4 &&
                    matrix[frontX + dx[2]][frontY + dy[2]] != 7) {
                        q.push(make_pair(frontX + dx[2], frontY + dy[2]));
                        visited[frontX + dx[2]][frontY + dy[2]] = visited[frontX][frontY] + 1;
                    }
                }
            }
            if(matrix[frontX + dx[3]][frontY + dy[3]] != 0) {
                if(visited[frontX + dx[3]][frontY + dy[3]] == 0) {
                    if(matrix[frontX + dx[3]][frontY + dy[3]] != 2 &&
                    matrix[frontX + dx[3]][frontY + dy[3]] != 6 &&
                    matrix[frontX + dx[3]][frontY + dy[3]] != 7) {
                        q.push(make_pair(frontX + dx[3], frontY + dy[3]));
                        visited[frontX + dx[3]][frontY + dy[3]] = visited[frontX][frontY] + 1;
                    }
                }
            }
        }
        if(visited[frontX][frontY] == timeSpend - 1) break;
    }
    getAnswer();
}

void printVisited() {
    cout << endl;
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= column; j++) cout << visited[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; i++) {
        cin >> row >> column >> manholeX >> manholeY >> timeSpend;
        inputMatrix();
        solve();
        printVisited();
        cout << "#" << i << " " << answer << endl;
    }
}
