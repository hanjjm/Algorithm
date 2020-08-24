#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "", temp = "";
    int length = musicinfos.size();
    int musicLen = 0;
    for(int i = 0; i < m.length(); i++) {
        if(m[i] == '#') continue;
        if(i + 1 <= m.length() - 1 && m[i + 1] == '#') {
            temp += m[i] + 32;
        } else temp += m[i];
    }
    m = temp;
    
    for(int i = 0; i < length; i++) {
        int firstMusic = 60 * stoi(musicinfos[i].substr(0, 2)) + stoi(musicinfos[i].substr(3, 2));
        int secondMusic = 60 * stoi(musicinfos[i].substr(6, 2)) + stoi(musicinfos[i].substr(9, 2));
        int playTime = secondMusic - firstMusic;
        
        string info = musicinfos[i].substr(12);
        int infoLength = info.length(), index = 0;
        string music = "", record = "", recordMusic = "";
        
        for(int j = 0; j < infoLength; j++) {
            if(info[j] != ',' && index == 0) music += info[j];
            if(info[j] == ',') index++;
            if(info[j] != ',' && index == 1) {
                if(info[j] == '#') continue;
                if(info[j + 1] == '#') record += info[j] + 32;
                else record += info[j];
            }
        }
        
        index = 0;
        int count = 0;
        while(playTime > count) {
            recordMusic += record[index];
            index++;
            if(index >= record.length()) index = 0;
            count++;
        }
        if(recordMusic.find(m) <= 9999) {
            if(m[m.length() - 1] != '#' && recordMusic[recordMusic.find(m) + m.length()] != '#') {
                if(musicLen < playTime){
                    answer = music;
                    musicLen = playTime;
                }
            }
        }
    }
    
    if(answer == "") answer = "(None)";
    return answer;
}
