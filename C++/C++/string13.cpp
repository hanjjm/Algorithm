#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 기본 점수, 외부 링크 수(다른 외부로 연결된 수), 링크점수, 매칭점수
int solution(string word, vector<string> pages) {
    int answer = 0;
    
    
    for(int i = 0; i < word.length(); i++) {
        if(word[i] - 'A' >= 0 && word[i] - 'A' < 26) word[i] += 32;
    }
    
    for(int i = 0; i < pages.size(); i++) {
        for(int j = 0; j < pages[i].length(); j++) {
            if(pages[i][j] - 'A' >= 0 && pages[i][j] - 'A' < 26) pages[i][j] += 32;
        }
    }
    
    vector<vector<int>> link(20), outLink(20);
    vector<int> basic, linkPoint;
    vector<string> url;
    for(int i = 0; i < pages.size(); i++) {
        int count = 0, outToIn = 0, inToOut = 0;
        
        for(int j = 0; j < pages[i].length() - word.length(); j++) { // 문자 찾기
            if(word == pages[i].substr(j, word.length())) {
                if((pages[i][j - 1] - 'a' < 0 || pages[i][j - 1] - 'a' >= 26)
                  && (pages[i][j + word.length()] - 'a' < 0
                   || pages[i][j + word.length()] - 'a' >= 26)) count++;
            }
            
            if(pages[i].substr(j, 13) == "meta property") {
                int start = pages[i].substr(j).find("https");
                int end = pages[i].substr(j).find(">") - 2;
                url.push_back(pages[i].substr(j).substr(start, end - start));
            }
        }
        basic.push_back(count);
    }
    
    for(int i = 0; i < pages.size(); i++) {
        int count = 0, outToIn = 0, inToOut = 0;
        
        for(int j = 0; j < pages[i].length() - word.length(); j++) {
            if(pages[i].substr(j, 7) == "a href=") {\
                int start = pages[i].substr(j).find("https");
                int end = pages[i].substr(j).find(">") - 1;
                string outUrl = pages[i].substr(j).substr(start, end - start);
                // cout << outUrl << endl;
                for(int k = 0; k < url.size(); k++) {
                    if(outUrl == url[k]) link[i].push_back(k);
                }
            }
        }
    }
    
    for(int i = 0; i < pages.size(); i++) {
        for(int j = 0; j < link[i].size(); j++) {
            linkPoint.push_back(link[i].size()); // 외부링크
            // cout << link[i][j] << " ";
        }
        // cout << endl;
    }
    
    double arr[20] = {0, };
    double matchingPoint[20] = {0, };
    for(int i = 0; i < pages.size(); i++) {
        for(int j = 0; j < link[i].size(); j++) {
            arr[link[i][j]] += (linkPoint[i] / basic[i]);
            // cout << link[i][j] << " ";
        }
        // cout << endl;
    }
    
    for(int i = 0; i < basic.size(); i++) {
        matchingPoint[i] = basic[i] + arr[i];
        cout << matchingPoint[i] << " ";
    }
    
    return answer;
}
