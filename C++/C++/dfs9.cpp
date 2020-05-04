#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
set<vector<string>> s;
bool chk[9];
 int answer = 0;
bool check(string id, int idx, vector<string> &ban) {
    if (id.size() != ban[idx].size()) return false;
    for (int i = 0; i < id.size(); i++) {
        if (ban[idx][i] == '*' ) continue;
        if (id[i] != ban[idx][i]) return false;
    }
    return true;
}
void dfs(int idx, int cnt, vector<string>&user, vector<string>&ban, vector<string> &res) {
    if (cnt == ban.size()) {
        vector<string> tmp;
        tmp = res;
        // for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
        // cout << '\n';
        sort(tmp.begin(), tmp.end());
        s.insert(tmp);
        // answer++;
        return;
    }
    
    for (int i = 0; i < user.size(); i++) {
         if (!chk[i]) {
             if (check(user[i], cnt, ban)) {
                
                 chk[i] = true;
                 res.push_back(user[i]);
                 dfs(i+1, cnt+1, user, ban, res);
                 res.pop_back();
                 chk[i] = false;
             }
        }
    }
}
int solution(vector<string> user, vector<string> ban) {
vector<string> res;
    dfs(0,0,user, ban, res);
    answer = s.size();
    return answer;
}
