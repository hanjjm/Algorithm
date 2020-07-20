#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.length();
    int div = s.length() / 2;
    if(len == 1 || len == 2) return s;
    if(len % 2 == 0) {
        answer += s[div - 1];
        answer += s[div];
    } else answer += s[div];
    return answer;
}
