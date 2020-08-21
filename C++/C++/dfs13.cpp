#include <vector>
#include <iostream>
#include <stack>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    stack<pair<int, int>> st;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(picture[i][j] != 0) {
                st.push(make_pair(i, j));
                int color = picture[i][j];
                picture[i][j] = 0;
                int size = 1;
                while(true) {
                    if(st.empty()) break;
                    int first = st.top().first;
                    int second = st.top().second;
                    st.pop();
                    for(int k = 0; k < 4; k++) {
                        if(first + dir[k][0] >= 0 && first + dir[k][0] < picture.size()
                          && second + dir[k][1] >= 0 && second + dir[k][1] < picture[0].size()) {
                            if(picture[first + dir[k][0]][second + dir[k][1]] == color) {
                                st.push(make_pair(first + dir[k][0], second + dir[k][1]));
                                picture[first + dir[k][0]][second + dir[k][1]] = 0;
                                size++;
                            }
                        }
                    }
                }
                number_of_area++;
                max_size_of_one_area = max(size, max_size_of_one_area);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

