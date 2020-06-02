#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<int, int>> house;
int matrix[20][20];
int N, M, K;
int answer;

void initMatrix() {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) matrix[i][j] = 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            matrix[i][j] = temp;
            if(temp == 1) house.push_back(make_pair(i, j));
        }
    }
}

void distanceCheck() {
    int range = N + 1;
    while(true) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int houseCount = 0;
                for(int k = 0; k < house.size(); k++) {
                    if(abs(house[k].first - i) + abs(house[k].second - j) < range) houseCount++;
                }
                if(pow(range, 2) + pow(range - 1, 2) <= M * houseCount) answer = max(answer, houseCount);
            }
        }
        if(range == 1) break;
        range--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    
    for(int i = 1; i <= testCase; i++) {
        answer = 0;
        cin >> N >> M;
        house.clear();
        initMatrix();
        distanceCheck();
        cout << "#" << i << " " << answer << endl;
    }
}
