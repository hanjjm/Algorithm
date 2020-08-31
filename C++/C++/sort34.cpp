#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> timeT;

void stringToInt(vector<string> timetable) {
    for(int i = 0; i < timetable.size(); i++) {
        timeT.push_back(60 * stoi(timetable[i].substr(0, 2)) + stoi(timetable[i].substr(3, 2)));
    }
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int temp = 0;
    
    sort(timetable.begin(), timetable.end());
    stringToInt(timetable);
    
    int busTime = 540, lastBus = 540 + (n - 1) * t;
    for(int i = 1; i <= n; i++) {
        if(busTime != lastBus) {
            for(int j = 1; j <= m; j++) {
                if(!timeT.empty() && timeT[0] <= busTime) {
                    timeT.erase(timeT.begin() + 0);
                }
            }
        } else {
            for(int j = 1; j <= m - 1; j++) {
                if(!timeT.empty() && timeT[0] <= busTime) {
                    timeT.erase(timeT.begin() + 0);
                }
            }
            if(timeT.empty() || lastBus < timeT[0]) temp = lastBus;
            else if(lastBus == timeT[0]) temp = lastBus - 1;
            else temp = timeT[0] - 1;
        }
        busTime += t;
    }
    
    if(temp / 60 <= 9) answer += "0";
    answer += to_string(temp / 60);
    answer += ":";
    if(temp % 60 <= 9) answer += "0";
    answer += to_string(temp % 60);
    
    return answer;
}
