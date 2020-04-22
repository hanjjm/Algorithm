#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int bigIndex = people.size() - 1;
    int smallIndex = 0;
    while(true) {
        int bigSize = people[bigIndex];
        bigIndex--;
        if(smallIndex == bigIndex) {
            if(people[smallIndex] + bigSize <= limit) answer++;
            else answer += 2;
            break;
        }
        if(people[smallIndex] + bigSize <= limit) smallIndex++;
        if(smallIndex == bigIndex) {
            answer += 2;
            break;
        }
        answer++;
    }
    
    return answer;
}
