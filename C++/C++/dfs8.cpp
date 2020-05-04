#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;
set<string> s;
bool visited[8] = {false, };

bool banCheck(string user_id, string banned_id) {
    int userLen = user_id.length(), bannedLen = banned_id.length();
    if(userLen != bannedLen) return false;
    int flag = 1;
    for(int i = 0; i < userLen; i++) {
        if(banned_id[i] == '*') continue;
        if(banned_id[i] == user_id[i]) continue;
        flag = 0;
        break;
    }
    return flag == 1 ? true : false;
}

void dfs(vector<string> user_id, vector<string> banned_id, int index) {
    int userLen = user_id.size(), bannedLen = banned_id.size();
    if(index == bannedLen) {
        string temp = "";
        for(int i = 0; i < 8; i++) {
            if(visited[i] == true) temp += to_string(i);
        }
        s.insert(temp);
        return;
    }
    for(int i = 0; i < userLen; i++) {
        if(banCheck(user_id[i], banned_id[index]) && visited[i] == false) {
            visited[i] = true;
            dfs(user_id, banned_id, index + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int userLen = user_id.size();
    vector<pair<string, int>> user;
    dfs(user_id, banned_id, 0);
    int answer = s.size();
    return answer;
}
