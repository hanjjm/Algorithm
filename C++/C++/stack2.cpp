#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<pair<char, int>> st;
    int laser = 0;
    
    int len = arrangement.size();
    for(int i = 0; i < len; i++) {
        if(st.empty()) laser = 0;
        if(i != len - 1 && arrangement[i] == '(' && arrangement[i + 1] != ')')
            st.push(make_pair('(', laser));
        else if(i != len - 1 && arrangement[i] == '(' && arrangement[i + 1] == ')') laser++;
        else if(i != 0 && arrangement[i] == ')' && arrangement[i - 1] != '(') {
            answer += laser - st.top().second + 1;
            st.pop();
        }
    }
    
    return answer;
}
