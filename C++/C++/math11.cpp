#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(string str1, string str2) {
    int str1Length = str1.length(), str2Length = str2.length();
    vector<string> str1Vec, str2Vec;
    
    for(int i = 0; i < str1Length; i++) {
        if(str1[i] >= 'a' - 0 && str1[i] <= 'z' - 0) str1[i] -= 32;
    }
    
    for(int i = 0; i < str2Length; i++) {
        if(str2[i] >= 'a' - 0 && str2[i] <= 'z' - 0) str2[i] -= 32;
    }
    
    for(int i = 0; i < str1Length - 1; i++) {
        if(str1[i] >= 'A' - 0 && str1[i] <= 'Z' - 0
          && str1[i + 1] >= 'A' - 0 && str1[i + 1] <= 'Z' - 0) {
            str1Vec.push_back(str1.substr(i, 2));
        }
    }
    
    for(int i = 0; i < str2Length - 1; i++) {
        if(str2[i] >= 'A' - 0 && str2[i] <= 'Z' - 0
          && str2[i + 1] >= 'A' - 0 && str2[i + 1] <= 'Z' - 0) {
            str2Vec.push_back(str2.substr(i, 2));
        }
    }
    
    int vec1Size = str1Vec.size(), vec2Size = str2Vec.size(), count = 0;
    bool check[1000] = {false, };
    for(int i = 0; i < vec1Size; i++) {
        for(int j = 0; j < vec2Size; j++) {
            if(check[j] == false && str1Vec[i] == str2Vec[j]) {
                check[j] = true;
                count++;
                break;
            }
        }
    }
    
    if(vec1Size + vec2Size == 0) return 65536;
    int answer = floor(65536 * count / (vec1Size + vec2Size - count));
    return answer;
}
