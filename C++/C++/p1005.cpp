//
//  p1005.cpp
//  C++
//
//  Created by KimHanJu on 09/09/2019.
//  Copyright © 2019 KimHanJu. All rights reserved.
//

// RUNTIME ERROR

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    int testCase;
    
    cin >> testCase;
    
    while(testCase --> 0) {
        int buildingCount, ruleCount;
        
        cin >> buildingCount >> ruleCount;
        
        int delay[buildingCount];
        int front[ruleCount];
        vector<int> back[ruleCount];
        
        for(int i = 0; i < buildingCount; i++) cin >> delay[i];
        
        for(int i = 0; i < ruleCount; i++) {
            int first, second;
            cin >> first >> second;
            back[first-1].push_back(second-1);
            front[second-1] += 1;
        }
        
        int goalBuilding;
        
        cin >> goalBuilding;
        
        queue<int> queue;
        
        for(int i = 0; i < ruleCount; i++) if(front[i] == 0) queue.push(i);
        
        int finalTime[ruleCount];
        
        while(front[goalBuilding-1] != 0) {
            int queueFront = queue.front();
            queue.pop();
            
            for(int value : back[queueFront]){
                finalTime[value] = max(finalTime[value], finalTime[queueFront] + delay[queueFront]);
                queue.push(value);
            }
        }
        
        cout << finalTime[goalBuilding-1] + delay[goalBuilding-1];
    }
}
