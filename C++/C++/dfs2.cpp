#include <string>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int arr[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) arr[i][j] = computers[i][j];
    }
    
    stack<pair<int, int>> st;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 1) {
                arr[i][j] = 0;
                arr[j][i] = 0;
                st.push(make_pair(i, j));
                while(!st.empty()) {
                    pair<int, int> stTop = st.top();
                    st.pop();
                    for(int k = 0; k < n; k++) {
                        if(arr[stTop.second][k] == 1) {
                            st.push(make_pair(stTop.second, k));
                            arr[stTop.second][k] = 0;
                            arr[k][stTop.second] = 0;
                        }
                    }
                }
                answer++;
            }
        }
    }
    
    return answer;
}
