#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    char operand[6][3] = {{'+', '-', '*'}, {'+', '*', '-'}, {'*', '+', '-'},
                         {'*', '-', '+'}, {'-', '+', '*'}, {'-', '*', '+'}};
    
    vector<long long> number;
    vector<char> oper;
    string temp = "";
    
    for(int i = 0; i < expression.length(); i++) {
        if(expression[i] - '0' >= 0 && expression[i] - '0' <= 9) temp += expression[i];
        else {
            number.push_back(stoi(temp));
            oper.push_back(expression[i]);
            temp = "";
        }
        if(i == expression.length() - 1) number.push_back(stoi(temp));
    }
    
    for(int i = 0; i < 6; i++) {
        vector<long long> copyNum = number;
        vector<char> copyOper = oper;
        
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < copyOper.size(); k++) {
                if(copyOper[k] == operand[i][j]) {
                    if(copyOper[k] == '+') {
                        copyNum[k] += copyNum[k + 1];
                        copyNum.erase(copyNum.begin() + k + 1);
                        copyOper.erase(copyOper.begin() + k);
                        k--;
                    } else if(copyOper[k] == '-') {
                        copyNum[k] -= copyNum[k + 1];
                        copyNum.erase(copyNum.begin() + k + 1);
                        copyOper.erase(copyOper.begin() + k);
                        k--;
                    } else {
                        copyNum[k] *= copyNum[k + 1];
                        copyNum.erase(copyNum.begin() + k + 1);
                        copyOper.erase(copyOper.begin() + k);
                        k--;
                    }
                }
            }
        }
        answer = max(answer, abs(copyNum[0]));
    }
    
    return answer;
}
