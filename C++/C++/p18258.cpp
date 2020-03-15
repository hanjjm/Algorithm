//
//  p18258.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <queue>
#include <cstring>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    queue<int> queue;
    
    for(int i = 0; i < num; i++) {
        char order[6];
        scanf("%s", order);
        
        if(!strcmp(order, "push")) {
            int stNum;
            scanf("%d", &stNum);
            queue.push(stNum);
        } else if(!strcmp(order, "pop")) {
            if(queue.empty()) printf("-1\n");
            else {
                printf("%d\n", queue.front());
                queue.pop();
            }
        } else if(!strcmp(order, "size")) {
            printf("%d\n", queue.size());
        } else if(!strcmp(order, "empty")) {
            if(queue.empty()) printf("1\n");
            else printf("0\n");
        } else if(!strcmp(order, "front")) {
            if(queue.empty()) printf("-1\n");
            else printf("%d\n", queue.front());
        } else if(!strcmp(order, "back")) {
            if(queue.empty()) printf("-1\n");
            else printf("%d\n", queue.back());
        }
    }
}
