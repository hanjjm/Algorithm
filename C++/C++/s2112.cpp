//
//  s2112.cpp
//  C++
//
//  Created by KimHanJu on 2020/05/27.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;
int depth, width, standard;
int matrix[15][22];
int minNum = 987654321;

void inputMatrix() {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 22; j++) matrix[i][j] = 2;
    }
    for(int i = 1; i <= depth; i++) {
        for(int j = 1; j <= width; j++) cin >> matrix[i][j];
    }
}

bool passCheck() {
    for(int i = 1; i <= width; i++) {
        int dep = 1, tempMax = 0;
        for(int j = 1; j <= depth; j++) {
            if(matrix[j][i] == matrix[j + 1][i]) dep++;
            else {
                tempMax = max(tempMax, dep);
                dep = 1;
            }
            if(dep == standard) continue;
        }
        if(tempMax < standard) return false;
    }
    return true;
}

void dfs(int index, int count) {
    if(index == depth) {
        minNum = depth;
        return;
    }
    
    if(passCheck()) {
        minNum = min(minNum, count + 1);
        return;
    }
    
    int originalColor = matrix[index][0];
    dfs(index + 1, count);
    for(int i = index; i <= width; i++) matrix[index][i] = 0;
    dfs(index + 1, count + 1);
    for(int i = index; i <= width; i++) matrix[index][i] = 1;
    dfs(index + 1, count + 1);
    for(int i = 1; i <= width; i++) matrix[index][i] = originalColor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    for(int i = 0; i < testCase; i++) {
        cin >> depth >> width >> standard;
        inputMatrix();
        minNum = 987654321;

        if(passCheck()) {
            cout << "#" << i + 1 << " " << 0 << endl;
            continue;
        }

        dfs(0, 0);
        
        cout << "#" << i + 1 << " " << minNum << endl;
    }
}

//#include <iostream>
//using namespace std;
//int depth, width, standard;
//int matrix[15][22];
//int copyM[15][22];
//bool selected[13];
//int arr[13];
//int minNum = 987654321;
//pair<int, int> selected2[13];
//
//void inputMatrix() {
//    for(int i = 0; i < 15; i++) {
//        for(int j = 0; j < 22; j++) matrix[i][j] = 2;
//    }
//    for(int i = 1; i <= depth; i++) {
//        for(int j = 1; j <= width; j++) cin >> matrix[i][j];
//    }
//}
//
//void copyMatrix() {
//    for(int i = 0; i < 15; i++) {
//        for(int j = 0; j < 22; j++) copyM[i][j] = matrix[i][j];
//    }
//}
//
//bool passCheck() {
//    for(int i = 1; i <= width; i++) {
//        int dep = 1, tempMax = 0;
//        for(int j = 1; j <= depth; j++) {
//            if(copyM[j][i] == copyM[j + 1][i]) dep++;
//            else {
//                tempMax = max(tempMax, dep);
//                dep = 1;
//            }
//            if(dep == standard) continue;
//        }
//        if(tempMax < standard) return false;
//    }
//    return true;
//}
//
//void solve(int number) {
//    copyMatrix();
//    for(int i = 0; i < depth; i++) {
//        if(selected2[i].first == -1) continue;
//        for(int j = 1; j <= width; j++) {
//            copyM[i + 1][j] = selected2[i].second;
//        }
//    }
//    if(passCheck()) minNum = min(minNum, number);
//    return;
//}
//
//void dfs2(int index, int count, int number) {
//    if(minNum != 987654321) return;
//    if(count == number) {
//        solve(number);
//        for(int i = 0; i < depth; i++) {
////            cout << selected2[i].second << " ";
//        }
////        cout << endl;
//        return;
//    }
//
//    for(int i = 0; i < depth; i++) {
//        if(selected2[i].second == -1) continue;
//        selected2[i].second = 0;
//        dfs2(i, count + 1, number);
//    }
//}
//
//void dfs(int index, int count, int number) {
//    if(count == number) {
//        for(int i = 0; i < depth; i++) {
//            if(selected[i]) selected2[i] = make_pair(arr[i] , 0);
//            else selected2[i] = make_pair(-1, -1);
////            if(selected[i]) cout << arr[i] << " ";
//        }
////        cout << endl;
//        dfs2(0, 0, number);
//        return;
//    }
//
//    for(int i = index; i < depth; i++) { // index
//        if(selected[i] == true) continue;
//        selected[i] = true;
//        dfs(i, count + 1, number);
//        selected[i] = false;
//    }
//}
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//
//    int testCase;
//    cin >> testCase;
//
//    for(int i = 0; i < testCase; i++) {
//        cin >> depth >> width >> standard;
//        inputMatrix();
//        int number = 1;
//        minNum = 987654321;
//        for(int i = 0; i < depth; i++) { // 조합을 위한 초기화
//            arr[i] = i + 1;
//            selected[i] = false;
//        }
//
//        copyMatrix();
//        if(passCheck()) {
//            cout << "#" << i + 1 << " " << 0 << endl;
//            continue;
//        }
//
//        while(true) {
//            dfs(0, 0, number);
//            number++;
//            if(minNum != 987654321) break;
//            if(number == standard) minNum = standard;
//        }
//        cout << "#" << i + 1 << " " << minNum << endl;
//    }
//}
