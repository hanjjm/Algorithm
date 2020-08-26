#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int columnSize, length, answer = 0;
int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
bool check[8] = {false, };
vector<string> vec;

void dfs(int count, int index, int target, vector<vector<string>> relation) {
    if(count == target) {
        set<string> s;
        string num = "";
        for(int i = 0; i < length; i++) {
            string temp = "";
            for(int j = 0; j < columnSize; j++) {
                if(check[j] == true) temp += relation[i][arr[j]];
            }
            s.insert(temp);
        }
        if(s.size() == length) {
            string temp = "";
            for(int i = 0; i < columnSize; i++) {
                if(check[i] == true) temp += to_string(arr[i]);
            }
            
            for(int i = 0; i < vec.size(); i++) {
                int same = 0;
                for(int j = 0; j < vec[i].length(); j++) {
                    if(temp.find(vec[i][j]) <= 1000) same++;
                }
                if(same == vec[i].length()) return;
            }
            
            vec.push_back(temp);
            answer++;
        }
        return;
    }
    
    for(int i = index; i < columnSize; i++) {
        if(check[i] == true) continue;
        check[i] = true;
        
        dfs(count + 1, i, target, relation);
        check[i] = false;
    }
}

int solution(vector<vector<string>> relation) {
    columnSize = relation[0].size();
    length = relation.size();
    
    for(int i = 1; i <= columnSize; i++) dfs(0, 0, i, relation);
    
    return answer;
}
