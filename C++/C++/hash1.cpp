#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < participant.size(); i++) {
        if(i == participant.size() - 1) {
            answer = participant.at(i);
        } else if(participant.at(i).compare(completion.at(i)) != 0) {
            answer = participant.at(i);
            break;
        }
    }
    
    return answer;
}
