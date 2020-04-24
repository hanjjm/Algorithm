#include <string>
#include <vector>

using namespace std;

int strike(int target, int num) {
    int strikeNum = 0;
    if(target / 100 == num / 100) strikeNum++;
    if((target % 100) / 10 == (num % 100) / 10) strikeNum++;
    if(target % 10 == num % 10) strikeNum++;
    return strikeNum;
}

int ball(int target, int num) {
    int ballNum = 0;
    if(target / 100 == (num % 100) / 10) ballNum++;
    if(target / 100 == num % 10) ballNum++;
    if((target % 100) / 10 == num / 100) ballNum++;
    if((target % 100) / 10 == num % 10) ballNum++;
    if(target % 10 == num / 100) ballNum++;
    if(target % 10 == (num % 100) / 10) ballNum++;
    return ballNum;
}

int solution(vector<vector<int>> baseball) {
    vector<int> enable;
    int answer = 0;
    for(int i = 123; i <= 987; i++) {
        int index = 0;

        if((i % 100) / 10 == 0 || i % 10 == 0) continue;
        if(i / 100 == (i % 100) / 10) continue;
        if(i / 100 == i % 10) continue;
        if((i % 100) / 10 == i % 10) continue;

        for(int j = 0; j < baseball.size(); j++) {
            int eachStrike = strike(i, baseball[j][0]);
            int eachBall = ball(i, baseball[j][0]);

            if(baseball[j][1] == eachStrike && baseball[j][2] == eachBall) {
                index++;
            }
        }
        if(index == baseball.size()) enable.push_back(i);
    }
    return enable.size();
}
