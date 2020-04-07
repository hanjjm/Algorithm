#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b ? true : false;
}

int solution(vector<int> citations) {
    int answer = 0, index = 0;
    int length = citations.size();
    sort(citations.begin(), citations.end(), compare);
    while(true) {
        index = 0;
        for(int i = 0; i < length; i++) {
            if(citations[i] > answer) index++;
        }
        if(index > answer) answer++;
        else break;
    }
    return answer;
}
