#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> answer;
    
    for(int i = 0; i < clothes.size(); i++) {
        if(answer.find(clothes[i][1]) == answer.end())
            answer[clothes[i][1]] = 1; //아무것도 안입는 경우를 이 때 +해줌.
        else answer[clothes[i][1]]++;
    }
    
    int result = 1;
    unordered_map<string, int>::iterator iter;
    for(iter = answer.begin(); iter != answer.end(); iter++) {
        result += iter -> second * result;
    }
    
    return result - 1; //아무것도 안입은거 하나 빼기.
}
