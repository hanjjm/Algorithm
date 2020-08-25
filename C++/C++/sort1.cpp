// 처음에 head랑 number를 따로 sort하려다가 너무 길어져버렸다..합치면 훨씬 깔끔해질듯!
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    string headA = "", headB = "";
    for(int i = 0; i < a.first.length(); i++) {
        if(a.first[i] - '0' >= 0 && a.first[i] - '0' <= 9) break;
        string temp = "";
        if(a.first[i] - 'A' >= 0 && a.first[i] - 'A' <= 26) {
            temp += a.first[i] + 32;
        } else temp += a.first[i];
        headA += temp;
    }
    for(int i = 0; i < b.first.length(); i++) {
        if(b.first[i] - '0' >= 0 && b.first[i] - '0' <= 9) break;
        string temp = "";
        if(b.first[i] - 'A' >= 0 && b.first[i] - 'A' <= 26) {
            temp += b.first[i] + 32;
        } else temp += b.first[i];
        headB += temp;
    }
    
    if(headA < headB) {
        return true;
    } else if(headA == headB) {
        string numberA = "", numberB = "";
    
        string temp = "";
        int flag = 0;
        for(int i = 0; i < a.first.length(); i++) {
            if(flag && (a.first[i] - '0' > 9 || a.first[i] - '0' < 0)) break;
            if(a.first[i] - '0' >= 0 && a.first[i] - '0' <= 9) {
                temp += a.first[i];
                flag = 1;
            }
        }
        numberA = temp;
        
        temp = ""; flag = 0;
        for(int i = 0; i < b.first.length(); i++) {
            if(flag && (b.first[i] - '0' > 9 || b.first[i] - '0' < 0)) break;
            if(b.first[i] - '0' >= 0 && b.first[i] - '0' <= 9) {
                temp += b.first[i];
                flag = 1;
            }
        }
        numberB = temp;

        for(int i = 0; i < numberA.length(); i++) {
            if(numberA[i] != '0') {
                numberA = numberA.substr(i);
                break;
            }
        }

        for(int i = 0; i < numberB.length(); i++) {
            if(numberB[i] != '0') {
                numberB = numberB.substr(i);
                break;
            }
        }
        
        int numA = stoi(numberA), numB = stoi(numberB);
        if(numA < numB) return true;
        else if(numA == numB) {
            if(a.second < b.second) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<pair<string, int>> vec;
    for(int i = 1; i <= files.size(); i++) vec.push_back(make_pair(files[i - 1], i));
    sort(vec.begin(), vec.end(), compare);
    for(int i = 0; i < files.size(); i++) answer.push_back(vec[i].first);
    return answer;
}
