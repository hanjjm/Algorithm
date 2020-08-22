#include <string>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int index = 0;
    int stringLen = dartResult.length();
    int score[3] = {0, 0, 0};
    for(int i = 0; i < stringLen; i++) {
        if(dartResult[i] - '0' >= 0 && dartResult[i] - '0' <= 9) {
            if(dartResult[i] == '1' && dartResult[i + 1] == '0') {
                score[index] += 10;
                i++;
            } else score[index] += dartResult[i] - '0';
            if(dartResult[i + 1] == 'D') score[index] = pow(score[index], 2);
            if(dartResult[i + 1] == 'T') score[index] = pow(score[index], 3);
            if(i + 2 < stringLen && dartResult[i + 2] == '*') {
                if(index != 0) score[index - 1] *= 2;
                score[index] *= 2;
            }
            if(i + 2 < stringLen && dartResult[i + 2] == '#') score[index] *= -1;
            index++;
        }
    }
    
    return score[0] + score[1] + score[2];
}
