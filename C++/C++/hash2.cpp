#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 1; i < phone_book.size(); i++) {
        if(!phone_book.at(i - 1).compare(phone_book.at(i).substr(0, phone_book.at(i - 1).size()))) {
            answer = false;
            break;
        }
    }
    
    return answer;
}
