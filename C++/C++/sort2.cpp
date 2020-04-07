#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string first, string second) {
    return first + second > second + first ? true : false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> vec;
    int length = numbers.size();
    
    for(int i = 0; i < length; i++) {
        vec.push_back(to_string(numbers[i]));
    }
    sort(vec.begin(), vec.end(), compare);
    for(int i = 0; i < length; i++) answer += vec[i];
    if(answer[0] == '0') return "0";
    
    return answer;
}
