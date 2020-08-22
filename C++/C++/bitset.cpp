#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        string map1 = bitset<16>(arr1[i]).to_string();
        string map2 = bitset<16>(arr2[i]).to_string();
        string line = "";
        
        for(int j = 16 - n; j < 16; j++) {
            if(map1[j] == '1' || map2[j] == '1') {
                line += "#";
            } else line += " ";
        }
        answer.push_back(line);
    }
    
    return answer;
}
