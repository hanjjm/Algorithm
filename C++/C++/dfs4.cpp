#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
int matrix[102][102];
int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void init() {
    for(int i = 0; i < 102; i++) {
        for(int j = 0; j < 102; j++) matrix[i][j] = 0;
    }
}

void initMatrix(int m, int n, vector<vector<int>> picture) {
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) matrix[i][j] = picture[i - 1][j - 1];
    }
}

pair<int, int> dfs(int m, int n) {
    int many = 0, count = 0;
    vector<int> bigSize;
    stack<pair<int, int>> st;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            count = 1;
            if(matrix[i][j] == 0) continue;
            st.push(make_pair(i, j));
            int temp = matrix[i][j];
            matrix[i][j] = 0;
            while(true) {
                pair<int, int> stTop = st.top();
                st.pop();
                
                for(int i = 0; i < 4; i++) {
                    if(temp == matrix[stTop.first + direction[i][0]][stTop.second + direction[i][1]]) {
                        st.push(make_pair(stTop.first + direction[i][0], stTop.second + direction[i][1]));
                        matrix[stTop.first + direction[i][0]][stTop.second + direction[i][1]] = 0;
                        count++;
                    }
                }
                if(st.empty()) {
                    bigSize.push_back(count);
                    break;
                }
            }
            
            many++;
        }
    }
    
    pair<int, int> ans;
    sort(bigSize.begin(), bigSize.end());
    ans.first = many;
    ans.second = bigSize[bigSize.size() - 1];
    return ans;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    init();
    initMatrix(m, n, picture);
    pair<int, int> tempAnswer;
    tempAnswer = dfs(m, n);
    
    vector<int> answer(2);
    answer[0] = tempAnswer.first;
    answer[1] = tempAnswer.second;
    return answer;
}
