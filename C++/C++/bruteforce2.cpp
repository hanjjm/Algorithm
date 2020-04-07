#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int length = numbers.size();
    vector<int> sosu;
    sosu.push_back(2);
    int num = pow(10, length);
    for(int i = 2; i < num; i++) {
        for(int j = 2; j <= sqrt(i) + 1; j++) {
            if(i % j == 0) break;
            if(j == (int)sqrt(i) + 1) sosu.push_back(i);
        }
    }
    
    string save = numbers;
    int saveLen = save.length();
    int sosuSize = sosu.size();
    for(int i = 0; i < sosuSize; i++) {
        numbers = save;
        string temp = to_string(sosu[i]);
        int tempLen = temp.length();
        for(int j = 0; j < tempLen; j++) {
            int numLen = numbers.length();
            int index = 1;
            for(int k = 0; k < numLen; k++) {
                if(temp[j] == numbers[k]) {
                    numbers.erase(k, 1);
                    index = 0;
                    break;
                }
            }
            if(index) break;
        }
        if(tempLen == saveLen - numbers.length()) answer++;
    }
    
    return answer;
}
