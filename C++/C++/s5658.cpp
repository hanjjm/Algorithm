//
//  s5658.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/18.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;
int testCase, N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> testCase;
    set<int> s;
    string number;
    
    for(int i = 0; i < testCase; i++) {
        cin >> N >> K;
        cin >> number;
        int len = number.length() / 4;
        
        for(int l = 0; l < len; l++) {
            for(int j = 0; j < 4; j++) {
                string temp = "";
                for(int k = j * len; k < j * len + len; k++) {
                    temp += number[k];
                }
                int eachNum = 0, tempNum = 0;
                for(int k = 0; k < temp.length(); k++) {
                    if(temp[k] == 'A') tempNum = 10;
                    else if(temp[k] == 'B') tempNum = 11;
                    else if(temp[k] == 'C') tempNum = 12;
                    else if(temp[k] == 'D') tempNum = 13;
                    else if(temp[k] == 'E') tempNum = 14;
                    else if(temp[k] == 'F') tempNum = 15;
                    else tempNum = temp[k] - '0';
                    eachNum += tempNum * pow(16, temp.length() - 1 - k);
                }
                s.insert(eachNum);
                temp = "";
            }
            number = number[number.length() - 1] + number.substr(0, number.length() - 1);
        }
        
        int index = 0;
        for(auto iter = s.rbegin(); iter != s.rend(); iter++) { // set의 원소 반환
            index++;
            if(index == K) cout << "#" << i + 1 << " " << *iter << endl;
        }
        s.clear();
    }
    return 0;
}
