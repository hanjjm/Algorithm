//
//  test111.cpp
//  C++
//
//  Created by KimHanJu on 2020/09/27.
//  Copyright © 2020 KimHanJu. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = { // 0은 숫자가 비어있는 칸, 999는 열 초과했으니 무시!
        {1, 999, 999, 999, 999},
        {0, 3, 999, 999, 999},
        {0, 4, 0, 999, 999},
        {0, 0, -1, 0, 999},
        {0, 19, 0, 0, 0}
    };
        
    for(int i = 1; i < 5; i++) { // 총 4번 반복 (1행은 이미 들어가있으니)
        int index = -1;
        for(int j = 0; j < i + 1; j++) { // 각 행의 열까지 찾는데, 여기서 0이 아닌 숫자가 처음에 어디 나오는가?
            if(arr[i][j] != 0) index = j; // 4행을 예를 들면, 3번째에 처음으로 0이 아닌 -1이 나오므로 index = 2;
        }
        
        int right = index + 1;
        int left = index - 1;
        
        while(right < i) { // right가 행의 크기보다 커지면 종료
            arr[i][right] = arr[i - 1][right - 1] - arr[i][right - 1];
            right++; // 한칸씩 오른쪽으로 이동
        }
        
        while(left >= 0) { // left가 0보다 작아지면 종료
            arr[i][left] = arr[i - 1][left] - arr[i][left + 1];
            left--;
        }
    }
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}
