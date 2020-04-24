#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    vector<int> sosu;
    
    sosu.push_back(2);
    for(int i = 2; i < 3000; i++) {
        for(int j = 2; j <= sqrt(i) + 1; j++) {
            if(i % j == 0) break;
            if(j == (int)sqrt(i) + 1) sosu.push_back(i);
        }
    }
    
    for(int i = 0; i < nums.size() - 2; i++) {
        for(int j = i + 1; j < nums.size() - 1; j++) {
            for(int k = j + 1; k < nums.size(); k++) {
                for(int l = 0; l < sosu.size(); l++) {
                    if(nums[i] + nums[j] + nums[k] == sosu[l]) {
                        answer++;
                        break;
                    }
                }
            }
        }
    }
    
    return answer;
}
