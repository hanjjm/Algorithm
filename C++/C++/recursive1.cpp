#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

bool balanceCheck(string str) {
    int len = str.length();
    int first = 0, second = 0;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') first++;
        else second++;
    }
    if(first == second) return true;
    else return false;
}

bool rightCheck(string str) {
    if(!balanceCheck(str)) return false;
    int len = str.length();
    stack<char> st;
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') st.push('(');
        else {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;
}

string solve(string p) {
    if(rightCheck(p)) return p;
    string u, v;
    int pLength = p.length();
    string temp = "";
    for(int i = 0; i < pLength; i++) {
        temp += p[i];
        if(balanceCheck(temp)) {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if(rightCheck(u)) {
        if(rightCheck(v)) return u + v;
        else return u + solve(v);
    } else {
        string tempFirst = "(" + solve(v) + ")";
        string tempSecond = u.substr(1, u.length() - 2);
        for(int i = 0; i < tempSecond.length(); i++) {
            if(tempSecond[i] == '(') tempSecond[i] = ')';
            else tempSecond[i] = '(';
        }
        return tempFirst + tempSecond;
    }
}

string solution(string p) {
    string answer = "";
    if(p.length() == 0) return ""; // 1번
    answer = solve(p);
    return answer;
}
