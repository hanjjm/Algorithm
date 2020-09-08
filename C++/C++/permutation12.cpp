#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    
    do {
        for(int k = 0; k < weak.size(); k++) {
            int weakArr[200] = {0, };
            for(int i = 0; i < weak.size(); i++) weakArr[weak[i]] = 1;
            int index = weak[k];

            for(int i = 0; i < dist.size(); i++) {
                for(int j = 0; j < dist[i] + 1; j++) {
                    weakArr[index] = 0;
                    index++;
                    if(index == n) index = 0;
                }

                int start = index;
                while(weakArr[index] != 1) {
                    index++;
                    if(index == n) index = 0;
                    if(index == start) {
                        answer = min(answer, i + 1);
                        break;
                    }
                }
            }
            
        }
    } while(next_permutation(dist.begin(), dist.end()));
    
    if(answer == 987654321) answer = -1;
    return answer;
}
