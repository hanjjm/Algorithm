#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int len = commands.size();
    for(int i = 0; i < len; i++) {
        int num[commands[i][1] - commands[i][0] + 1];
        int smallLen = commands[i][1] - commands[i][0] + 1;
        for(int j = 0; j < smallLen; j++) {
            num[j] = array[commands[i][0] - 1 + j];
        }
        sort(num, num + smallLen);
        answer.push_back(num[commands[i][2] - 1]);
    }
    
    return answer;
}
