#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = -1;
    stack<string> st;
    st.push(begin);
    
    while(!st.empty()) {
        string stTop = st.top();
        answer++;
        if(stTop == target) break;
        else if(answer >= 51) {
            answer = 0;
            break;
        }
        st.pop();
        for(int i = 0; i < words.size(); i++) {
            int index = 0;
            for(int j = 0; j < words[i].size(); j++) {
                if(stTop[j] != words[i][j]) index++;
            }
            if(index == 1) {
                st.push(words[i]);
                for(int j = 0; j < words[i].size(); j++) words[i][j] = '0';
            }
        }
    }
    if(st.empty()) answer = 0;
    return answer;
}
