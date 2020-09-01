#include <string>
#include <vector>
#include <cmath>

using namespace std;
int phone[4][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -2}};

pair<int, int> getPoint(int number) {
    if(number == 1) return make_pair(0, 0);
    if(number == 2) return make_pair(0, 1);
    if(number == 3) return make_pair(0, 2);
    if(number == 4) return make_pair(1, 0);
    if(number == 5) return make_pair(1, 1);
    if(number == 6) return make_pair(1, 2);
    if(number == 7) return make_pair(2, 0);
    if(number == 8) return make_pair(2, 1);
    if(number == 9) return make_pair(2, 2);
    if(number == -1) return make_pair(3, 0);
    if(number == 0) return make_pair(3, 1);
    if(number == -2) return make_pair(3, 2);
    return make_pair(-1, -1);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int testCase = numbers.size();
    
    pair<int, int> left = make_pair(3, 0);
    pair<int, int> right = make_pair(3, 2);
    
    for(int i = 0; i < testCase; i++) {
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left = getPoint(numbers[i]);
            continue;
        }
        
        if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right = getPoint(numbers[i]);
            continue;
        }
        
        pair<int, int> next = getPoint(numbers[i]);
        
        int leftDistance = abs(next.first - left.first) + abs(next.second - left.second);
        int rightDistance = abs(next.first - right.first) + abs(next.second - right.second);
        
        if(leftDistance < rightDistance) {
            answer += "L";
            left = getPoint(numbers[i]);
        } else if(leftDistance > rightDistance) {
            answer += "R";
            right = getPoint(numbers[i]);
        } else {
            if(hand == "right") {
                answer += "R";
                right = getPoint(numbers[i]);
            } else {
                answer += "L";
                left = getPoint(numbers[i]);
            }
        }
    }
    
    return answer;
}
