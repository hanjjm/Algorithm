#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    vector<char> character;
    character.push_back('A'); character.push_back('C');
    character.push_back('F'); character.push_back('J');
    character.push_back('M'); character.push_back('N');
    character.push_back('R'); character.push_back('T');
    int answer = 0;
    
    do {
        int testCase = data.size();
        bool flag = true;
        
        for(int i = 0; i < testCase; i++) {
            int first = -1, second = -1;
            for(int j = 0; j < 8; j++) {
                if(character[j] == data[i][0]) first = j;
                if(character[j] == data[i][2]) second = j;
            }
            if(data[i][3] == '=') {
                if(abs(first - second) - 1 != data[i][4] - '0') flag = false;
            } else if(data[i][3] == '<') {
                if(abs(first - second) - 1 >= data[i][4] - '0') flag = false;
            } else if(data[i][3] == '>') {
                if(abs(first - second) - 1 <= data[i][4] - '0') flag = false;
            }
        }
        
        if(flag) answer++;
    } while(next_permutation(character.begin(), character.end()));
    
    return answer;
}

/* 시간초과
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool check[8];
int answer;

void solve(vector<string> copyData, vector<char> vec) {
    int testCase = copyData.size();
    for (int i = 0; i < testCase; i++) {
        int first = -1, second = -1;
        for(int j = 0; j < 8; j++) {
            if(vec[j] == copyData[i][0]) first = j;
            if(vec[j] == copyData[i][2]) second = j;
        }
        if(copyData[i][3] == '=') {
            if(abs(first - second) - 1 != copyData[i][4] - '0') return;
        } else if(copyData[i][3] == '<') {
            if(abs(first - second) - 1 >= copyData[i][4] - '0') return;
        } else if(copyData[i][3] == '>') {
            if(abs(first - second) - 1 <= copyData[i][4] - '0') return;
        }
    }
    answer++;
    return;
}
 
void combination(int count, vector<string> data, vector<char> vec, char character[8]) {
    if (count == 8) {
        solve(data, vec);
        return;
    }
 
    for (int i = 0; i < 8; i++) {
        if (check[i] == true) continue;
        check[i] = true;
        vec.push_back(character[i]);
        combination(count + 1, data, vec, character);
        vec.pop_back();
        check[i] = false;
    }
}

int solution(int n, vector<string> data) { // data = n x n,
    vector<char> vec;
    answer = 0;
    char character[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    combination(0, data, vec, character);
    return answer;
}
*/
