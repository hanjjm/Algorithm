#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> translateKey(vector<vector<int>> key) {
    vector<vector<int>> temp = key;
    int keySize = key.size(), index = 0;
    for(int i = 0; i < keySize; i++) {
        for(int j = 0; j < keySize; j++) {
            key[i][j] = temp[keySize - 1 - j][index];
        }
        index++;
    }
    return key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int lockSize = lock.size(), keySize = key.size();
    
    for(int i = 0; i < 4; i++) {
        key = translateKey(key); // 키 90도씩 회전
        vector<pair<int, int>> point;
        
        for(int j = 0; j < keySize; j++) { // 좌표 입력
            for(int k = 0; k < keySize; k++) {
                if(key[j][k] == 1) point.push_back(make_pair(j, k));
            }
        }
        
        int indexX = -lockSize, indexY = -lockSize;
        while(true) {
            vector<vector<int>> tempLock = lock;
            
            for(int j = 0; j < point.size(); j++) {
                if(point[j].first + indexX >= 0 && point[j].first + indexX < lockSize
                   && point[j].second + indexY >= 0 && point[j].second + indexY < lockSize) {
                    tempLock[point[j].first + indexX][point[j].second + indexY]++;
                }
            }
            
            bool flag = true;
            for(int j = 0; j < lockSize; j++) {
                for(int k = 0; k < lockSize; k++) {
                    if(tempLock[j][k] == 0 || tempLock[j][k] == 2) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            
            if(flag) return true;
            if(indexY == lockSize) {
                indexX++;
                indexY = -lockSize;
            } else indexY++;
            if(indexX == lockSize && indexY == lockSize) break;
        }
    }
    
    return false;
}
