#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    
    int moveLength = moves.size();
    int boardLength = board.size();
    for(int i = 0; i < moveLength; i++) {
        for(int j = 0; j < boardLength; j++) {
            if(!board[j][moves[i] - 1]) continue;
            if(!st.empty()) {
                if(st.top() == board[j][moves[i] - 1]) {
                    answer += 2;
                    st.pop();
                } else st.push(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            } else {
                st.push(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}
