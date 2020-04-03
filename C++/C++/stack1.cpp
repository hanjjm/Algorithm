#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<int> st;
    int height = heights.size();
    for(int i = 0; i < height; i++) st.push(heights[i]);
    
    for(int i = 0; i < height; i++) {
        while(!st.empty()) st.pop();
        for(int j = 0; j < height - i; j++) st.push(heights[j]);
        
        int stTop = st.top();
        while(true) {
            if(!st.empty()) {
                if(stTop < st.top()) break; //이 부분 에러가 많이 떴는데 empty 조건을 같이 주니 segmentation fault가 계속 떴음
            } else break;
            st.pop();
        }

        if(st.empty()) answer.push_back(0);
        else answer.push_back(st.size());
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}
