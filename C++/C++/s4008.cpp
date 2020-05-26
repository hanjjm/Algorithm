//
//  s4008.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/26.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int number[12];
int operation[4];
int selectNum[11];
int maxNum, minNum;
vector<int> vec;

void inputNumber(int numberCase) {
    for(int i = 0; i < 12; i++) number[i] = 0;
    for(int i = 0; i < numberCase; i++) cin >> number[i];
}

//void inputOperation() { // 시간초과
//    for(int i = 0; i < 11; i++) operation[i] = 0;
//    int eachOperation;
//    vector<int> temp;
//    for(int i = 0; i < 4; i++) {
//        cin >> eachOperation;
//        if(i == 0) {
//            for(int j = 0; j < eachOperation; j++) temp.push_back(0);
//        } else if(i == 1) {
//            for(int j = 0; j < eachOperation; j++) temp.push_back(1);
//        } else if(i == 2) {
//            for(int j = 0; j < eachOperation; j++) temp.push_back(2);
//        } else if(i == 3) {
//            for(int j = 0; j < eachOperation; j++) temp.push_back(3);
//        }
//    }
//    for(int i = 0; i < temp.size(); i++) operation[i] = temp[i];
//}

void solve(int operationCase) {
    int answer = number[0];
    for(int i = 0; i < operationCase; i++) {
        if(vec[i] == 0) answer += number[i + 1];
        else if(vec[i] == 1) answer -= number[i + 1];
        else if(vec[i] == 2) answer *= number[i + 1];
        else if(vec[i] == 3) answer /= number[i + 1];
    }
    maxNum = max(maxNum, answer);
    minNum = min(minNum, answer);
}

void dfs(int count, int target) {
    if(count == target) {
        solve(target);
        return;
    }
    
//    for(int i = 0; i < target; i++) { // 시간초과
//        if(selectNum[i] == 1) continue;
//        selectNum[i] = 1;
//        vec.push_back(operation[i]);
//        dfs(count + 1, target);
//        vec.pop_back();
//        selectNum[i] = 0;
//    }
    
    for(int i = 0; i < 4; i++){
        if(operation[i] > 0){
            vec.push_back(i);
            operation[i] -= 1;
            dfs(count + 1, target);
            operation[i] += 1;
            vec.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 0; i < testCase; i++) {
        int numberCase;
        cin >> numberCase;
        for(int j = 0; j < 4; j++) cin >> operation[j];
        maxNum = -100000000;
        minNum = 100000000;
//        inputOperation();
        inputNumber(numberCase);
        dfs(0, numberCase - 1);
        cout << "#" << i + 1 << " " << maxNum - minNum << endl;
    }
}
