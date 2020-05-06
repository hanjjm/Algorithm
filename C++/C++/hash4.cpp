#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first > b.first) return true;
    else if(a.first == b.first) {
        if(a.second < b.second) return true;
    }
    return false;
}

bool compare2(pair<string, int> a, pair<string, int> b) {
    if(a.second > b.second) return true;
    else return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genreList, playList;
    vector<pair<int, int>> eachList;
    vector<pair<string, int>> forSort;
    int genreSize = genres.size(), playSize = plays.size();
    
    for(int i = 0; i < genreSize; i++) {
        if(genreList.find(genres[i]) == genreList.end()) genreList[genres[i]] = plays[i];
        else genreList[genres[i]] += plays[i];
    }
    
    for(pair<string, int> atom : genreList) {
        forSort.push_back(make_pair(atom.first, atom.second));
    }
    
    sort(forSort.begin(), forSort.end(), compare2);
    
    for(int j = 0; j < forSort.size(); j++) {
        for(int i = 0; i < genreSize; i++) {
            if(forSort[j].first == genres[i]) eachList.push_back(make_pair(plays[i], i));
        }
        sort(eachList.begin(), eachList.end(), compare);
        for(int i = 0; i < eachList.size(); i++) {
            if(i == 2) break;
            answer.push_back(eachList[i].second);
        }
        eachList.clear();
    }
    
    return answer;
}
