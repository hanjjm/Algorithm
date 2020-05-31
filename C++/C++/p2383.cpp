//
//  p2383.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/30.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int room[12][12] = {0, };
int stairGroup[10] = {0, };
int timeSpend = 987654321;
vector<pair<int, int>> people;
vector<pair<int, int>> stair;
vector<int> stairLength;
vector<vector<int>> stairPeople(2);
vector<pair<int, int>> peopleToStair;
vector<pair<int, int>> copyPeopleToStair;

void inputMatrix(int length) {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) room[i][j] = 0;
    }
    for(int i = 0; i < 10; i++) stairGroup[i] = 0;
    for(int i = 1; i <= length; i++) {
        for(int j = 1; j <= length; j++) {
            cin >> room[i][j];
            if(room[i][j] == 1) people.push_back(make_pair(i, j));
            else if(room[i][j] <= 10 && room[i][j] >= 2) {
                stair.push_back(make_pair(i, j));
                stairLength.push_back(room[i][j]);
            }
        }
    }
}

void getPeopleToStair(int length) {
    for(int i = 0; i < people.size(); i++) {
        int firstStair = abs(people[i].first - stair[0].first) + abs(people[i].second - stair[0].second);
        int secondStair = abs(people[i].first - stair[1].first) + abs(people[i].second - stair[1].second);
        peopleToStair.push_back(make_pair(firstStair, secondStair));
    }
}

void solve(int peopleNum) {
    int minTime = 1;
    copyPeopleToStair.clear();
    for(int i = 0; i < peopleToStair.size(); i++) {
        copyPeopleToStair.push_back(peopleToStair[i]);
    }
    stairPeople[0].clear();
    stairPeople[1].clear();
    int endPeople = 0;
    
    while(true) {
        int endFirst = 0, endSecond = 0;
        for(int i = 0; i < peopleNum; i++) {
            if(stairGroup[i] == 0) copyPeopleToStair[i].first--;
            else if(stairGroup[i] == 1)copyPeopleToStair[i].second--;
        }
        for(int i = 0; i < peopleNum; i++) {
            if(copyPeopleToStair[i].first == 0) {
                if(stairPeople[0].size() < 3) {
                    stairPeople[0].push_back(stairLength[0] + 1);
                    copyPeopleToStair[i].first--;
                } else if(stairPeople[0].size() == 3) continue;
            } else if(copyPeopleToStair[i].second == 0) {
                if(stairPeople[1].size() < 3) {
                    stairPeople[1].push_back(stairLength[1] + 1);
                    copyPeopleToStair[i].second--;
                } else if(stairPeople[1].size() == 3) continue;
            }
        }
            
        for(int i = 0; i < stairPeople[0].size(); i++) {
            stairPeople[0][i]--;
            if(stairPeople[0][i] == 0) endFirst++;
        }
        for(int i = 0; i < stairPeople[1].size(); i++) {
            stairPeople[1][i]--;
            if(stairPeople[1][i] == 0) endSecond++;
        }
        for(int i = 0; i < endFirst; i++) {
            stairPeople[0].erase(stairPeople[0].begin() + 0);
        }
        for(int i = 0; i < endSecond; i++) {
            stairPeople[1].erase(stairPeople[1].begin() + 0);
        }
        
        for(int i = 0; i < peopleNum; i++) {
            if(copyPeopleToStair[i].first == 0) {
                if(stairPeople[0].size() < 3) stairPeople[0].push_back(stairLength[0]);
                else if(stairPeople[0].size() == 3) copyPeopleToStair[i].first++;
            } else if(copyPeopleToStair[i].second == 0) {
                if(stairPeople[1].size() < 3) stairPeople[1].push_back(stairLength[1]);
                else if(stairPeople[1].size() == 3) copyPeopleToStair[i].second++;
            }
        }
        
        endPeople += (endFirst + endSecond);
        if(endPeople == peopleNum) break;
        minTime++;
    }
    timeSpend = min(timeSpend, minTime);
}

void combination(int length, int peopleNum, int count) {
    if(count == peopleNum) {
        solve(peopleNum);
        return;
    }
    
    stairGroup[count] = 0;
    combination(length, peopleNum, count + 1);
    stairGroup[count] = 1;
    combination(length, peopleNum, count + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        int length;
        cin >> length;
        timeSpend = 987654321;
        people.clear();
        stair.clear();
        stairLength.clear();
        peopleToStair.clear();
        inputMatrix(length);
        getPeopleToStair(length);
        int peopleNum = people.size();
        combination(length, peopleNum, 0);
        cout << "#" << i + 1 << " " << timeSpend + 1 << endl;
    }
}
