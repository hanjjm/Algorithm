#include <iostream>
#include <vector>
using namespace std;
int timer, batteryCount;
vector<pair<int, int>> firstMan, secondMan;
vector<vector<int>> battery(9);
int answer;

void walkFirstMan() {
    firstMan.clear();
    pair<int, int> firstStep = make_pair(1, 1), nextStep;
    firstMan.push_back(firstStep);
    int step;
    nextStep = firstStep;
    for(int i = 0; i < timer; i++) {
        cin >> step;
        if(step == 0) nextStep = nextStep;
        else if(step == 1) nextStep = make_pair(nextStep.first - 1, nextStep.second);
        else if(step == 2) nextStep = make_pair(nextStep.first, nextStep.second + 1);
        else if(step == 3) nextStep = make_pair(nextStep.first + 1, nextStep.second);
        else if(step == 4) nextStep = make_pair(nextStep.first, nextStep.second - 1);
        firstMan.push_back(nextStep);
    }
}

void walkSecondMan() {
    secondMan.clear();
    pair<int, int> firstStep = make_pair(10, 10), nextStep;
    secondMan.push_back(firstStep);
    int step;
    nextStep = firstStep;
    for(int i = 0; i < timer; i++) {
        cin >> step;
        if(step == 0) nextStep = nextStep;
        else if(step == 1) nextStep = make_pair(nextStep.first - 1, nextStep.second);
        else if(step == 2) nextStep = make_pair(nextStep.first, nextStep.second + 1);
        else if(step == 3) nextStep = make_pair(nextStep.first + 1, nextStep.second);
        else if(step == 4) nextStep = make_pair(nextStep.first, nextStep.second - 1);
        secondMan.push_back(nextStep);
    }
}

void inputBattery() {
    for(int i = 1; i <= batteryCount; i++) battery[i].clear();
    for(int i = 1; i <= batteryCount; i++) {
        int dx, dy, range, power;
        cin >> dx >> dy >> range >> power;
        battery[i].push_back(dy);
        battery[i].push_back(dx);
        battery[i].push_back(range);
        battery[i].push_back(power);
    }
}

void printStep() {
    cout << endl << "A의 이동 : ";
    for(int i = 0; i < timer; i++) cout << "(" << firstMan[i].first << ", " << firstMan[i].second << ") ";
    cout << endl << "B의 이동 : ";
    for(int i = 0; i < timer; i++) cout << "(" << secondMan[i].first << ", " << secondMan[i].second << ") ";
}

void solveOne() {
    vector<int> batteryInA;
    vector<int> batteryInB;
    for(int i = 0; i <= timer; i++) {
        batteryInA.clear(); batteryInB.clear();
        if(abs(firstMan[i].first - battery[1][0]) + abs(firstMan[i].second - battery[1][1]) <= battery[1][2]) batteryInA.push_back(1);
        if(abs(secondMan[i].first - battery[1][0]) + abs(secondMan[i].second - battery[1][1]) <= battery[1][2]) batteryInB.push_back(1);
        if(batteryInA.size() == 0 && batteryInB.size() == 0) continue;
        answer += battery[1][3];
        
    }
}

void solve() {
    vector<int> batteryInA;
    vector<int> batteryInB;
    for(int i = 0; i <= timer; i++) {
        int energyA = 0, energyB = 0;
        batteryInA.clear(); batteryInB.clear();
        for(int j = 1; j <= batteryCount; j++) {
            if(abs(firstMan[i].first - battery[j][0]) + abs(firstMan[i].second - battery[j][1]) <= battery[j][2]) batteryInA.push_back(j);
            if(abs(secondMan[i].first - battery[j][0]) + abs(secondMan[i].second - battery[j][1]) <= battery[j][2]) batteryInB.push_back(j);
        }
        
        if(batteryInA.size() == 0) {
            if(batteryInB.size() == 1) energyB += battery[batteryInB[0]][3];
            else if(batteryInB.size() >= 2) {
                for(int j = 0; j < batteryInB.size(); j++) {
                    if(battery[batteryInB[j]][3] > energyB) energyB = battery[batteryInB[j]][3];
                }
            }
            answer += energyB;
        }
        
        if(batteryInB.size() == 0) {
            if(batteryInA.size() == 1) energyA += battery[batteryInA[0]][3];
            else if(batteryInA.size() >= 2) {
                for(int j = 0; j < batteryInA.size(); j++) {
                    if(battery[batteryInA[j]][3] > energyA) energyA = battery[batteryInA[j]][3];
                }
            }
            answer += energyA;
        }
        
        int compareNum = 0;
        if(batteryInA.size() >= 1 && batteryInB.size() >= 1) {
            for(int j = 0; j < batteryInA.size(); j++) {
                for(int k = 0; k < batteryInB.size(); k++) {
                    energyA = battery[batteryInA[j]][3];
                    energyB = battery[batteryInB[k]][3];
                    if(batteryInA[j] == batteryInB[k]) compareNum = max(compareNum, energyA);
                    else compareNum = max(compareNum, energyA + energyB);
                }
            }
            answer += compareNum;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    
    for(int i = 1; i <= testCase; i++) {
        cin >> timer >> batteryCount;
        walkFirstMan();
        walkSecondMan();
//        printStep();
        inputBattery();
        answer = 0;
        if(batteryCount == 1) solveOne();
        else solve();
        cout << "#" << i << " " <<  answer << endl;
    }
}
