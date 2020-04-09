#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {
            if(lost[i] == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
            }
        }
    }
    for(int i = 0; i < lost.size(); i++) {
        for(int j = 0; j < reserve.size(); j++) {
           if(lost[i] - 1 == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            } else if(lost[i] + 1 == reserve[j]) {
                lost[i] = -1;
                reserve[j] = -1;
                break;
            }
        }
    }
    for(int i = 0; i < lost.size(); i++) {
        if(lost[i] != -1) answer--;
    }
    return answer;
}
