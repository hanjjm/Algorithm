#include <string>
#include <vector>
#include <iostream>

using namespace std;
int first[5] = {1, 2, 3, 4, 5};
int second[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int third[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int fir = 0, sec = 0, thi = 0;
    int length = answers.size();
    for(int i = 0; i < length; i++) {
        if(answers[i] == first[i % 5]) fir++;
    }
    for(int i = 0; i < length; i++) {
        if(answers[i] == second[i % 8]) sec++;
    }
    for(int i = 0; i < length; i++) {
        if(answers[i] == third[i % 10]) thi++;
    }
    int maxNum = max(max(fir, sec), thi);
    if(maxNum == fir) answer.push_back(1);
    if(maxNum == sec) answer.push_back(2);
    if(maxNum == thi) answer.push_back(3);
    return answer;
}
