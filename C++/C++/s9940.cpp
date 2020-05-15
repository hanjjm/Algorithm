//
//  s9940.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/15.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int tc, number;
    cin >> tc;
    bool sel[100001];
    for(int i = 0; i < 100001; i++) sel[i] = false;
    
    for(int j = 0; j < tc; j++) {
        cin >> number;
        int flag = 0;
        for(int i = 1; i <= number; i++) sel[i] = false;
        for(int i = 1; i <= number; i++) {
            int temp;
            cin >> temp;
            sel[temp] = true;
        }
        for(int i = 1; i <= number; i++) {
            if(sel[i] == false) {
                flag = 1;
                break;
            }
        }
        if(flag) cout << "#" << j + 1 << " " << "NO" << endl;
        else cout << "#" << j + 1 << " " << "YES" << endl;
    }
}


//#include <iostream>
//#include <vector>
//using namespace std;
//int arr[100000] = {0, };
//bool sel[100000] = {false, };
//int number;
//int flag;
//vector<int> check;
//vector<int> vec;
//
//void permutation(int count) { // 숫자 너무 커지면.. 시간 너무 길어진다.
//    if(count == number) {
//        for(int i = 0; i < number; i++) {
//            if(check[i] != vec[i]) break;
//            if(i == number - 1) flag = 1;
//        }
//        if(flag) return;
//    }
//
//    for(int i = 0; i < number; i++) {
//        if(sel[i] == true) continue;
//        sel[i] = true;
//        vec.push_back(arr[i]);
//        permutation(count + 1);
//        sel[i] = false;
//        vec.pop_back();
//    }
//}
//
//int main() {
//    int tc;
//    cin >> tc;
//
//    for(int i = 0; i < tc; i++) {
//        cin >> number;
//        for(int i = 0; i < number; i++) {
//            int temp;
//            cin >> temp;
//            check.push_back(temp);
//            arr[i] = i + 1;
//        }
//        flag = 0;
//        permutation(0);
//        if(flag) cout << "#" << i + 1 << " " << "YES" << endl;
//        else cout << "#" << i + 1 << " " << "NO" << endl;
//        check.clear();
//        vec.clear();
//    }
//}
