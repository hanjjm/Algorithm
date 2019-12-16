//
//  p2941.cpp
//  C++
//
//  Created by KimHanJu on 2019/12/16.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string word;
    int result = 0;
    cin >> word;
    
    for(int i = 0; i < word.size(); i++) {
        if(word.at(i) == 'c' && i != word.size() - 1) {
            if(word.at(i + 1) == '=' || word.at(i + 1) == '-') i++;
        } else if(word.at(i) == 'd' && i != word.size() - 1) {
            if(word.at(i + 1) == 'z' && i != word.size() - 2) {
                if(word.at(i + 2) == '=') i += 2;
            }else if(i != word.size() - 1) {
                if(word.at(i + 1) == '-') i++;
            }
        } else if(word.at(i) == 'l' && i != word.size() - 1) {
             if(word.at(i + 1) == 'j') i++;
        } else if(word.at(i) == 'n' && i != word.size() - 1) {
            if(word.at(i + 1) == 'j') i++;
        } else if(word.at(i) == 's' && i != word.size() - 1) {
            if(word.at(i + 1) == '=') i++;
        } else if(word.at(i) == 'z' && i != word.size() - 1) {
            if(word.at(i + 1) == '=') i++;
        }
        result++;
    }
    
    if(word.size() == 1) result = 1;
    cout << result;
}
