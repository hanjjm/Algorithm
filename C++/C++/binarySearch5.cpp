#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int maxT = 200000000;
    int right = 2000000000;
    int left = 1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        int jump = 0;
        bool flag = false;
        
        for(int i = 0; i < stones.size(); i++) {
            if(stones[i] >= mid) jump = 0;
            else {
                jump++;
                if(jump == k) {
                    flag = true;
                    break;
                }
            }
        }
        
        if(flag) { // 실패
            right = mid - 1;
        } else { // 성공
            answer = mid;
            left = mid + 1;
        }
    }
    
    return answer;
}
