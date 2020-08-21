#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b) {
    if(a.first > b.first) return true;
    else if(a.first == b.first) {
        if(a.second < b.second) return true;
        else return false;
    } else return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double eachStage[200002] = {0, };
    double eachStagePlus[200002] = {0, };
    double fail[200002] = {0, };
    int stageLength = stages.size();
    
    for(int i = 0; i < stageLength; i++) {
        eachStage[stages[i]]++;
        eachStagePlus[stages[i]]++;
    }
    
    int plus = 0;
    for(int i = N; i >= 1; i--) {
        plus = eachStagePlus[i + 1];
        eachStagePlus[i] += plus;
    }
    
    vector<pair<double, int>> vec;
    for(int i = 1; i <= N; i++) {
        if(eachStagePlus[i] != 0) vec.push_back(make_pair(eachStage[i] / eachStagePlus[i], i));
        else vec.push_back(make_pair(0, i));
    }
    
    sort(vec.begin(), vec.end(), compare);
    for(int i = 0; i < N; i++) answer.push_back(vec[i].second);
    
    return answer;
}
