#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uidVec;
    unordered_map<string, string> um;
    int recordSize = record.size();
    
    for(int i = 0; i < recordSize; i++) {
        int index = 0;
        string uid = "", name = "";
        for(int j = 0; j < record[i].length(); j++) {
            if(record[i][j] == ' ') index++;
            if(index == 1 && record[i][j] != ' ') uid += record[i][j];
            if(index >= 2 && record[i][j] != ' ') name += record[i][j];
        }
        if(record[i][0] != 'L') um[uid] = name;
        uidVec.push_back(uid);
    }
    
    for(int i = 0; i < recordSize; i++) {
        if(record[i][0] == 'E') answer.push_back(um[uidVec[i]] + "님이 들어왔습니다.");
        else if(record[i][0] == 'L') answer.push_back(um[uidVec[i]] + "님이 나갔습니다.");
    }
    
    return answer;
}
