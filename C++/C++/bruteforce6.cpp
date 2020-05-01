#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<char> vec;
    vector<char> each;
    
    for(int i = 0; i < skill_trees.size(); i++) {
        for(int j = 0; j < skill_trees[i].size(); j++) {
            for(int k = 0; k < skill.length(); k++) {
                if(skill[k] == skill_trees[i][j]) each.push_back(skill_trees[i][j]);
            }
        }
        
        int check = 0;
        for(int j = 0; j < each.size(); j++) {
            if(each[j] == skill[j]) check++;
            cout << skill[j] << " : " << each[j] << endl;
        }
        if(check == each.size()) answer++;
        int eachSize = each.size();
        for(int j = 0; j < eachSize; j++) each.erase(each.begin() + 0);
    }
    
    return answer;
} 
