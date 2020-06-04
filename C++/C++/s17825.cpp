#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> vec(10000);
int maxNum = 0;
int matrix[32];
bool visited[32];
int list[10];

void initMatrix() {
    matrix[0] = 0;
    for(int i = 1; i <= 20; i++) matrix[i] = 2 * i;
    for(int i = 1; i <= 3 ; i++) matrix[20 + i] = 10 + 3 * i;
    for(int i = 1; i <= 3 ; i++) matrix[23 + i] = 30 - 2 * i;
    for(int i = 1; i <= 5 ; i++) matrix[26 + i] = 20 + 2 * i;
    for(int i = 0; i < 32; i++) visited[i] = false;
}

void solve(int index) {
    int answer = 0;
    int a = vec[index][0]; int b = vec[index][1];
    int c = vec[index][2]; int d = vec[index][3];
    for(int i = 0; i < a; i++) {
        
    }
    for(int i = 0; i < b; i++) {
        
    }
    for(int i = 0; i < c; i++) {
        
    }
    for(int i = 0; i < d; i++) {
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 10; i++) cin >> list[i];
    for(int i = 0; i < 4; i++) vec[i].push_back(0);
    initMatrix();
    int index = 0;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 10; l++) {
                    if(i + j + k + l == 10) {
                        vec[index].push_back(i); vec[index].push_back(j);
                        vec[index].push_back(k); vec[index].push_back(l);
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < 10000; i++) {
        if(vec[i].size() != 0) sort(vec[i].begin(), vec[i].end());
        int flag = 1;
        if(i != 0) {
            for(int j = 0; j < 4; j++) {
                if(vec[i][j] != vec[i - 1][j]) flag = 0;
            }
        }
        if(flag) vec[i].clear();
    }
    
    for(int i = 0; i < 10000; i++) {
        if(vec[i].size() == 0) continue;
        solve(i);
    }
}
