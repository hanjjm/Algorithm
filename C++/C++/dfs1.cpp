#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;

void BS(vector<int> numbers, int now, int index, int plus, int target) {
    plus += now;
    if(index == numbers.size() - 2) {
        if(target == plus) answer++;
        return;
    }
    index++;
    BS(numbers, numbers[index], index, plus, target);
    BS(numbers, -numbers[index], index, plus, target);
}

int solution(vector<int> numbers, int target) {
    numbers.push_back(-1);
    BS(numbers, numbers[0], 0, 0, target);
    BS(numbers, -numbers[0], 0, 0, target);
    return answer;
}
