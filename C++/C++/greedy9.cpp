#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int len = routes.size();
    int exit = routes[0][1];
    for(int i = 0; i < len - 1; i++) {
        if(exit > routes[i][1]) exit = routes[i][1];
        if(exit < routes[i + 1][0]) {
            exit = routes[i + 1][1];
            answer++;
        }
    }
    
    return answer + 1;
}
