#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
vector<pair<int, int>> timeVec;
int answer = 0;

void translate(vector<string> lines) {
    int lineSize = lines.size();
    
    for(int i = 0; i < lineSize; i++) { // 날짜 제거
        for(int j = 0; j < lines[i].length(); j++) {
            if(lines[i][j] == ' ') {
                lines[i] = lines[i].substr(j + 1);
                break;
            }
        }
    }
    
    for(int i = 0; i < lineSize; i++) { // 날짜 제거
        int endTime = 0, process = 0;
        
        endTime = 1000 * 60 * 60 * stoi(lines[i].substr(0, 2))
                + 1000 * 60 * stoi(lines[i].substr(3, 2))
                + 1000 * stoi(lines[i].substr(6, 2))
                + stoi(lines[i].substr(9, 3));
        
        string processTime = "";
        for(int j = 0; j < lines[i].length(); j++) {
            if(lines[i][j] == ' ') processTime = lines[i].substr(j + 1);
        }
        
        processTime = processTime.substr(0, processTime.length() - 1);
        process = 1000 * stoi(processTime.substr(0, 1));
        if(processTime[1] == '.') process += stoi(processTime.substr(2));
        
        timeVec.push_back(make_pair(endTime - process + 3000 + 1, endTime + 3000));
    }
    
    for(int i = 0; i < timeVec.size(); i++) {
        int temp = 1;
        
        for(int j = i + 1; j < timeVec.size(); j++) {
            if(timeVec[j].first < timeVec[i].second + 1000) temp += 1;
            // else break;
        }
        answer = max(answer, temp);
    }
    
}

int solution(vector<string> lines) {
    translate(lines);
    return answer;
}
