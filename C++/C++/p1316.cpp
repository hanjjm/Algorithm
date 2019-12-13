//
//  p1316.cpp
//  C++
//
//  Created by KimHanJu on 2019/12/14.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int testCase;
    cin >> testCase;
    int result = 0;
    bool alphabet[26];
    
    while(testCase --> 0) {
         for(int i = 0; i < 26; i++) alphabet[i] = false;
        string word;
        cin >> word;
        alphabet[word[0] - 'a'] = true;
        char prev = word[0];
        int index = 0;
        for(int i = 1; i < word.size(); i++) {
            if(word[i] != prev) {
                prev = word[i];
                if(alphabet[word[i] - 'a']) {
                    index = 1;
                    break;
                }
                else alphabet[word[i] - 'a'] = true;
            }
        }
        if(index == 0) result++;
    }
    cout << result;
}
