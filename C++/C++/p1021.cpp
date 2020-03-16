//
//  p1021.cpp
//  C++
//
//  Created by KimHanJu on 2020/03/16.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

deque<int> leftRotate(deque<int> deque) {
    deque.push_back(deque.front());
    deque.pop_front();
    return deque;
}

deque<int> rightRotate(deque<int> deque) {
    deque.push_front(deque.back());
    deque.pop_back();
    return deque;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> myDeque;
    int size, number;
    cin >> size >> number;
    for(int i = 1; i <= size; i++) myDeque.push_back(i);
    
    int result = 0;
    for(int i = 0; i < number; i++) {
        int where;
        cin >> where;

        int count = 0;
        int index = 0;
        for(int i = 0; i < myDeque.size(); i++) {
            if(myDeque[i] == where) index = i;
        }
        
        int tempNum = myDeque[index];
        if(myDeque.size() - index - 1 >= index) {
            while(myDeque.front() != tempNum) {
                myDeque = leftRotate(myDeque);
                count++;
            }
            myDeque.pop_front();
        } else {
            while(myDeque.front() != tempNum) {
                myDeque = rightRotate(myDeque);
                count++;
            }
            myDeque.pop_front();
        }
        result += count;
    }
    cout << result << endl;
}
