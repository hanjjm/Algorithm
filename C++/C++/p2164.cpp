//
//  p2164.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <string>
#include <queue>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    queue<int> queue;
    for(int i = 1; i <= N; i++) queue.push(i);
    
    while(queue.size() != 1) {
        queue.pop();
        int temp = queue.front();
        queue.push(temp);
        queue.pop();
    }
    
    printf("%d\n", queue.front());
}
