#include <iostream>
#include <vector>
using namespace std;
int matrix[20][20];
vector<vector<int>> vec(40);
int len, bridge, answer;

void inputMatrix() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) matrix[i][j] = 0;
    }
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) cin >> matrix[i][j];
    }
    for(int i = 0; i < 40; i++) vec[i].clear();
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) vec[i].push_back(matrix[i][j]);
    }
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) vec[len + i].push_back(matrix[j][i]);
    }
}

void solve() {
    answer = 0;
    for(int i = 0; i < 2 * len; i++) {
        int count = 0;
        int flag = 0;
        for(int j = 0; j < vec[i].size() - 1; j++) {
            if(abs(vec[i][j] - vec[i][j + 1]) >= 2) break;
            if(vec[i][j] == vec[i][j + 1]) count++;
            else if(vec[i][j] == vec[i][j + 1] - 1) {
                if(count >= bridge - 1) count = 0;
                else break;
            } else if(vec[i][j] == vec[i][j + 1] + 1) {
                count = 0;
                for(int k = 0; k < bridge; k++) {
                    if(vec[i][j + 1] != vec[i][j + 1 + k]) {
                        flag = 1;
                        break;
                    }
                    if(vec[i][j + 1] == vec[i][j + 1 + k]) count++;
                    if(count == bridge) {
                        j += bridge - 1;
                        if(j + 1 >= len) flag = 1;
                        count = -1;
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(j == vec[i].size() - 2) {
                if(vec[i][j] == vec[i][j + 1] + 1) break;
                answer++;
            }
            if(j == vec[i].size() - 1) {
                answer++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; i++) {
        cin >> len >> bridge;
        inputMatrix();
        solve();
        cout << "#" << i << " " << answer << endl;
    }
}
