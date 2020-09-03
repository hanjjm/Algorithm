#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int visited[100][100][2] = {0, };
int dx[4] = {1, 0, -1, 0}; // 하, 우, 상, 좌
int dy[4] = {0, 1, 0, -1};

struct Drone {
    int x, y, dir; // 0 - 좌우 & 1 - 상하
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int len = board.size();
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout << board[i][j] ;
        } cout << endl;
    }
    cout << endl;
    
    queue<Drone> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    
    while(!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int dir = q.front().dir;
        q.pop();
        
        if(dir == 0) {
            if(x == board.size() - 1 && y + 1 == board.size() - 1) {
                answer = visited[x][y][0];
                break;
            }
        } else {
            if(x + 1 == board.size() - 1 && y == board.size() - 1) {
                answer = visited[x][y][1];
                break;
            }
        }
        
        for(int i = 0; i < 4; i++) { // 상하좌우
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 이동 불가능
            if(dir == 0) { // 좌우
                if(nx < 0 || nx >= len || ny < 0 || ny + 1 >= len) continue;
            } else { // 상하
                if(nx < 0 || nx + 1 >= len || ny < 0 || ny >= len) continue;
            }
            
            if(dir == 0) {
                if(board[nx][ny] == 0 && board[nx][ny + 1] == 0 && visited[nx][ny][dir] == 0) {
                    visited[nx][ny][dir] = visited[x][y][dir] + 1;
                    q.push({nx, ny, dir});
                }
            } else {
                if(board[nx][ny] == 0 && board[nx + 1][ny] == 0 && visited[nx][ny][dir] == 0) {
                    visited[nx][ny][dir] = visited[x][y][dir] + 1;
                    q.push({nx, ny, dir});
                }
            }
        }
        
        if(dir == 0) {
            // 위가 기준
            if(x - 1 >= 0 && board[x - 1][y] == 0 && board[x - 1][y + 1] == 0) { // 왼쪽 위
                if(visited[x - 1][y][1] == 0) {
                    q.push({x - 1, y, 1});
                    visited[x - 1][y][1] = visited[x][y][0] + 1;
                }
            }
            
            if(x + 1 < board.size() && board[x + 1][y] == 0 && board[x + 1][y + 1] == 0) { // 왼쪽 아래
                if(visited[x][y][1] == 0) {
                    q.push({x, y, 1});
                    visited[x][y][1] = visited[x][y][0] + 1;
                }
            }
            
            if(x - 1 >= 0 && board[x - 1][y + 1] == 0 && board[x - 1][y] == 0) { // 오른쪽 위
                if(visited[x - 1][y + 1][1] == 0) {
                    q.push({x - 1, y + 1, 1});
                    visited[x - 1][y + 1][1] = visited[x][y][0] + 1;
                }
            }
            
            if(x + 1 < board.size() && board[x + 1][y] == 0 && board[x + 1][y + 1] == 0) { // 오른쪽 아래
                if(visited[x][y + 1][1] == 0) {
                    q.push({x, y + 1, 1});
                    visited[x][y + 1][1] = visited[x][y][0] + 1;
                }
            }
            
        } else {
            
            if(y - 1 >= 0 && board[x][y - 1] == 0 && board[x + 1][y - 1] == 0) { // 위 왼쪽
                if(visited[x][y - 1][0] == 0) {
                    q.push({x, y - 1, 0});
                    visited[x][y - 1][0] = visited[x][y][1] + 1;
                }
            }
            
            if(y + 1 < board.size() && board[x][y + 1] == 0 && board[x + 1][y + 1] == 0) { // 위 오른쪽
                if(visited[x][y][0] == 0) {
                    q.push({x, y, 0});
                    visited[x][y][0] = visited[x][y][1] + 1;
                }
            }
            
            if(y - 1 >= 0 && board[x][y - 1] == 0 && board[x + 1][y - 1] == 0) { // 아래 왼쪽
                if(visited[x + 1][y - 1][0] == 0) {
                    q.push({x + 1, y - 1, 0});
                    visited[x + 1][y - 1][0] = visited[x][y][1] + 1;
                }
            }
            
            if(y + 1 < board.size() && board[x + 1][y + 1] == 0 && board[x][y + 1] == 0) { // 아래 오른쪽
                if(visited[x + 1][y][0] == 0) {
                    q.push({x + 1, y, 0});
                    visited[x + 1][y][0] = visited[x][y][1] + 1;
                }
            }
            
        }
    }
    
    return answer - 1;
}

/* 좌우 좌표를 pair로 받았는데, visited 제대로 처리를 안해서 그런지 오류
#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> board) {
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int answer = 0;
    int arr[100][100][2] = {0, };
    arr[0][0][0] = 1; arr[0][1][0] = 1;
    pair<int, int> left = make_pair(0, 0);
    pair<int, int> right = make_pair(0, 1);
    pair<pair<int, int>, pair<int, int>> point;
    point = make_pair(left, right);
    
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(left, right));

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    
    int timer = 0;
    while(true) {
        // timer++;if(timer > 14) break;
        // cout << "size : " << q.size() << endl;
        pair<int, int> leftPoint = q.front().first;
        pair<int, int> rightPoint = q.front().second;
        q.pop();
         
        if(leftPoint.first == board.size() - 1 && leftPoint.second == board.size() - 1) break;
        if(rightPoint.first == board.size() - 1 && rightPoint.second == board.size() - 1) break;
        
        
        if(leftPoint.second > rightPoint.second
          && leftPoint.first == rightPoint.first) { // 위치 수정
            pair<int, int> temp = leftPoint;
            leftPoint = rightPoint;
            // cout<<"51";
            rightPoint = temp;
        }
        if(leftPoint.second == rightPoint.second
          && leftPoint.first > rightPoint.first) { // 위치 수정
            pair<int, int> temp = leftPoint;
            leftPoint = rightPoint;
            rightPoint = temp;
            // cout<<"44";
        }
        
        // cout << "L : (" << leftPoint.first + 1 << ", " << leftPoint.second+1 << ") R : (" << rightPoint.first+1 << ", " << rightPoint.second+1 << ")" << endl;
        
        if(leftPoint.first == rightPoint.first) { // 좌우방향
            if(rightPoint.second + 1 < board.size()) {
                // cout<<endl<<board[rightPoint.first][rightPoint.second + 1] << " " << arr[rightPoint.first][rightPoint.second + 1] << endl;
                
                if(board[rightPoint.first][rightPoint.second + 1] == 0
                  && arr[rightPoint.first][rightPoint.second + 1][0] == 0) { // 오른쪽 비었을 때
                    leftPoint.second++;
                    rightPoint.second++;
                    // cout<<"#";
                    q.push(make_pair(leftPoint, rightPoint));
                    arr[rightPoint.first][rightPoint.second][0] =
                        arr[rightPoint.first][rightPoint.second - 1][0] + 1;
            leftPoint.second--;
            rightPoint.second--;
                }
            }
            if(leftPoint.second - 1 >= 0) {
                if(board[leftPoint.first][leftPoint.second - 1] == 0
                  && arr[leftPoint.first][leftPoint.second - 1][0] == 0) { // 왼쪽 비었을 때
                    leftPoint.second--;
                    rightPoint.second--;
                    // cout <<"!";
                    q.push(make_pair(leftPoint, rightPoint));
                    arr[leftPoint.first][leftPoint.second][0] =
                        arr[leftPoint.first][leftPoint.second + 1][0] + 1;
            leftPoint.second++;
                    rightPoint.second++;
                }
            }
            if(rightPoint.first + 1 < board.size()) {
                if(board[rightPoint.first + 1][rightPoint.second] == 0
                  && arr[rightPoint.first + 1][rightPoint.second][1] == 0) { // 오른쪽 아래
                    if(board[leftPoint.first + 1][leftPoint.second] == 0) {
                        leftPoint.second++;
                        leftPoint.first++;
                        // cout<<"@";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[leftPoint.first][leftPoint.second][1] =
                            max(arr[leftPoint.first - 1][leftPoint.second - 1][0],
                           arr[rightPoint.first][rightPoint.second][0]) + 1;
                        if(arr[rightPoint.first][rightPoint.second][1] == 0){
                        arr[rightPoint.first][rightPoint.second][1] =
                            max(arr[leftPoint.first - 1][leftPoint.second - 1][0],
                           arr[rightPoint.first][rightPoint.second][0]) + 1;
                        }
                        leftPoint.second--;
                        leftPoint.first--;
                    }
                }
            }
            if(rightPoint.first - 1 >= 0) {
                if(board[rightPoint.first - 1][rightPoint.second] == 0
                  && arr[rightPoint.first - 1][rightPoint.second][1] == 0) { // 오른쪽 위
                    if(board[leftPoint.first - 1][leftPoint.second] == 0) {
                        leftPoint.second++;
                        leftPoint.first--;
                        // cout<<"%";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[leftPoint.first][leftPoint.second][1] =
                            max(arr[leftPoint.first + 1][leftPoint.second - 1][0],
                            arr[rightPoint.first][rightPoint.second][0]) + 1;
                        if( arr[rightPoint.first][rightPoint.second][1] == 0) {
                            arr[rightPoint.first][rightPoint.second][1] =
                                max(arr[leftPoint.first + 1][leftPoint.second - 1][0],
                            arr[rightPoint.first][rightPoint.second][0]) + 1;
                        }
                        leftPoint.second--;
                        leftPoint.first++;
                    }
                }
            }
            if(leftPoint.first + 1 < board.size()) {
                if(board[leftPoint.first + 1][leftPoint.second] == 0
                  && arr[leftPoint.first + 1][leftPoint.second][1] == 0) { // 왼쪽 아래
                    if(board[rightPoint.first + 1][rightPoint.second] == 0) {
                        rightPoint.second--;
                        rightPoint.first++;
                        // cout<<"*";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[rightPoint.first][rightPoint.second][1] =
                            max(arr[rightPoint.first - 1][rightPoint.second + 1][0],
                            arr[leftPoint.first][leftPoint.second][0]) + 1;
                        if(arr[leftPoint.first][leftPoint.second][1] == 0) {
                            arr[leftPoint.first][leftPoint.second][1] =
                                max(arr[rightPoint.first - 1][rightPoint.second + 1][0],
                            arr[leftPoint.first][leftPoint.second][0]) + 1;
                        }
            rightPoint.second++;
                        rightPoint.first--;
                    }
                }
            }
            // cout<<"  " << leftPoint.first - 1 << "   ";
            if(leftPoint.first - 1 >= 0) {
                if(board[leftPoint.first - 1][leftPoint.second] == 0
                  && arr[leftPoint.first - 1][leftPoint.second][1] == 0) { // 왼쪽 위
                    if(board[rightPoint.first - 1][rightPoint.second] == 0) {
                        rightPoint.second--;
                        rightPoint.first--;
                        // cout<<"~";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[rightPoint.first][rightPoint.second][1] =
                            max(arr[rightPoint.first + 1][rightPoint.second + 1][0],
                            arr[leftPoint.first][leftPoint.second][0]) + 1;
                        if(arr[leftPoint.first][leftPoint.second][1] == 0) {
                            arr[leftPoint.first][leftPoint.second][1] =
                                max(arr[rightPoint.first + 1][rightPoint.second + 1][0],
                            arr[leftPoint.first][leftPoint.second][0]) + 1;
                        }
            rightPoint.second++;
                        rightPoint.first++;
                    }
                }
            }
        } else {
            if(rightPoint.first + 1 < board.size()) {
                if(board[rightPoint.first + 1][rightPoint.second] == 0
                  && arr[rightPoint.first + 1][rightPoint.second][1] == 0) { // 아래 비었을 때
                    leftPoint.first++;
                    // cout<<")";
                    rightPoint.first++;
                    q.push(make_pair(leftPoint, rightPoint));
                    arr[rightPoint.first][rightPoint.second][1] =
                        arr[rightPoint.first - 1][rightPoint.second][1] + 1;
                leftPoint.first--;
            
                    rightPoint.first--;
                }
            }
            if(leftPoint.first - 1 >= 0) {
                if(board[leftPoint.first - 1][leftPoint.second] == 0
                  && arr[leftPoint.first - 1][leftPoint.second][1] == 0) { // 위 비었을 때
                    leftPoint.first--;
                    rightPoint.first--;
                    // cout<<"()";
                    q.push(make_pair(leftPoint, rightPoint));
                    arr[rightPoint.first][rightPoint.second][1] =
                        arr[rightPoint.first + 1][rightPoint.second][1] + 1;
            leftPoint.first++;
                    rightPoint.first++;
                }
            }
            if(rightPoint.second + 1 < board.size()) {
                if(board[leftPoint.first][leftPoint.second + 1] == 0
                  && arr[leftPoint.first][leftPoint.second + 1][0] == 0) { // 위 오른쪽
                    if(board[rightPoint.first][rightPoint.second + 1] == 0) {
                        rightPoint.second++;
                        rightPoint.first--;
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[rightPoint.first][rightPoint.second][0] =
                            max(arr[rightPoint.first + 1][rightPoint.second - 1][1],
                            arr[leftPoint.first][leftPoint.second][1]) + 1;
                        if(arr[leftPoint.first][leftPoint.second][0] == 0) {
                            arr[leftPoint.first][leftPoint.second][0] =
                            max(arr[rightPoint.first + 1][rightPoint.second - 1][1],
                            arr[leftPoint.first][leftPoint.second][1]) + 1;
                        }
            rightPoint.second--;
            
                        rightPoint.first++;
                    }
                }
            }
            if(rightPoint.second - 1 >= 0) {
                if(board[leftPoint.first][leftPoint.second - 1] == 0
                  && arr[leftPoint.first][leftPoint.second - 1][0] == 0) { // 위 왼쪽
                    if(board[rightPoint.first][rightPoint.second - 1] == 0) {
                        rightPoint.second--;
                        rightPoint.first--;
                        // cout<<"2";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[rightPoint.first][rightPoint.second][0] =
                            max(arr[rightPoint.first + 1][rightPoint.second + 1][1],
                            arr[leftPoint.first][leftPoint.second][1]) + 1;
                        if(arr[leftPoint.first][leftPoint.second][0] == 0) {
                        arr[leftPoint.first][leftPoint.second][0] =
                            max(arr[rightPoint.first + 1][rightPoint.second + 1][1],
                            arr[leftPoint.first][leftPoint.second][1]) + 1;
                        }
             rightPoint.second++;
                        rightPoint.first++;
                    }
                }
            }
            if(leftPoint.second - 1 >= 0) {
                if(board[rightPoint.first][rightPoint.second - 1] == 0
                  && arr[rightPoint.first][rightPoint.second - 1][0] == 0) { // 아래 왼쪽
                    if(board[leftPoint.first][leftPoint.second - 1] == 0) {
                        leftPoint.second--;
                        leftPoint.first++;
                        // cout<<"3";
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[leftPoint.first][leftPoint.second][0] =
                            max(arr[leftPoint.first - 1][leftPoint.second + 1][1],
                            arr[rightPoint.first][rightPoint.second][1]) + 1;
                        if(arr[rightPoint.first][rightPoint.second][0] == 0) {
                        arr[rightPoint.first][rightPoint.second][0] =
                            max(arr[leftPoint.first - 1][leftPoint.second + 1][1],
                            arr[rightPoint.first][rightPoint.second][1]) + 1;
                        }
            leftPoint.second++;
                        leftPoint.first--;
                    }
                }
            }
            if(leftPoint.second + 1 < board.size()) {
                if(board[rightPoint.first][rightPoint.second + 1] == 0
                  && arr[rightPoint.first][rightPoint.second + 1][0] == 0) { // 아래 오른쪽
                    if(board[leftPoint.first][leftPoint.second + 1] == 0) {
                        leftPoint.second++;
                        // cout<<"4";
                        leftPoint.first++;
                        q.push(make_pair(leftPoint, rightPoint));
                        arr[leftPoint.first][leftPoint.second][0] =
                            max(arr[leftPoint.first - 1][leftPoint.second - 1][1],
                            arr[rightPoint.first][rightPoint.second][1]) + 1;
                        if(arr[rightPoint.first][rightPoint.second][0] == 0) {
                        arr[rightPoint.first][rightPoint.second][0] =
                            max(arr[leftPoint.first - 1][leftPoint.second - 1][1],
                            arr[rightPoint.first][rightPoint.second][1]) + 1;
                        }
            leftPoint.second--;
                        // cout<<"4";
                        leftPoint.first--;
                    }
                }
            }
        }
        
        
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout << arr[i][j][0] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            cout << arr[i][j][1] << " ";
        }
        cout << endl;
    }
    
    return max(arr[board.size() - 1][board.size() - 1][0] - 1 , arr[board.size() - 1][board.size() - 1][1] - 1);
}
*/
