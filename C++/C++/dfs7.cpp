#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
bool visited[10000] = {false, };
vector<string> vec;

void dfs(vector<vector<string>> tickets, string next, int index, string now) {
    if(index == tickets.size()) {
        now += next;
       if(now.length() == 3 * (tickets.size() + 1)) vec.push_back(now);
        return;
    }
    int len = tickets.size();
    for(int i = 0; i < len; i++) {
        if(index == 0 && tickets[i][0] == "ICN") {
            visited[i] = true;
            next = tickets[i][1];
            now += "ICN";
            dfs(tickets, next, index + 1, now);
            now = "";
            next = "";
            visited[i] = false;
        } else if(next == tickets[i][0] && visited[i] == false) {
            visited[i] = true;
            string prev = next;
            next = tickets[i][1];
            now += tickets[i][0];
            dfs(tickets, next, index + 1, now);
            now = now.substr(0, now.length() - 3);
            next = prev;
            visited[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    dfs(tickets, "", 0, "");
    sort(vec.begin(), vec.end());
    string temp = "";
    for(int i = 1; i <= 3 * (tickets.size() + 1); i++) {
        if(i % 3 == 0) {
            temp += vec[0][i - 1];
            answer.push_back(temp);
            temp = "";
        } else temp += vec[0][i - 1];
    }
    return answer;
}
