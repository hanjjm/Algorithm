#include <iostream>
#include <vector>
using namespace std;
int N, W, H;
int matrix[15][12];
int copyM[15][12];
int answer = 0, maxNum = 0, brick = 0;

void initMatrix(int w, int h) {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 12; j++) matrix[i][j] = 0;
    }
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) cin >> matrix[i][j];
    }
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(matrix[i][j] != 0) brick++;
        }
    }
}

void reMatrix() {
    for(int i = 0; i < W; i++) {
        for(int j = H - 1; j >= 0; j--) {
            if(copyM[j][i] == 0) {
                int temp = j;
                while(true) {
                    if(copyM[temp][i] != 0) {
                        swap(copyM[j][i], copyM[temp][i]);
                        break;
                    }
                    temp--;
                    if(temp == -1) break;
                }
            }
        }
    }
}

void boom(int x, int y, int count) {
    copyM[x][y] = 0;
    answer++;
    for(int i = 1; i <= count; i++) { // 오
        if(y + i >= W) break;
        if(copyM[x][y + i] == 0) continue;
        if(copyM[x][y + i] == 1) {
            copyM[x][y + i] = 0;
            answer++;
        } else {
            boom(x, y + i, copyM[x][y + i] - 1);
        }
    }
    for(int i = 1; i <= count; i++) { // 왼
        if(y - i < 0) break;
        if(copyM[x][y - i] == 0) continue;
        if(copyM[x][y - i] == 1) {
            copyM[x][y - i] = 0;
            answer++;
        } else boom(x, y - i, copyM[x][y - i] - 1);
    }
    for(int i = 1; i <= count; i++) { // 아래
        if(x + i >= H) break;
        if(copyM[x + i][y] == 0) continue;
        if(copyM[x + i][y] == 1) {
            copyM[x + i][y] = 0;
            answer++;
        } else {
            boom(x + i, y, copyM[x + i][y] - 1);
        }
    }
    for(int i = 1; i <= count; i++) { // 위
        if(x - i < 0) break;
        if(copyM[x - i][y] == 0) continue;
        if(copyM[x - i][y] == 1) {
            copyM[x - i][y] = 0;
            answer++;
        } else {
            boom(x - i, y, copyM[x - i][y] - 1);
        }
    }
}

void solve(vector<int> vec, int len) {
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 12; j++) copyM[i][j] = matrix[i][j];
    }
    for(auto item : vec) {
        int target = item - 1;
//        cout << "target : " << target << endl;
        for(int i = 0; i <= H - 1; i++) {
            int numberis = copyM[i][target];
            if(numberis != 0) {
                boom(i, target, numberis - 1);
                reMatrix();
                break;
            }
        }
    }
//    cout << "answer : " << answer << endl;
    maxNum = max(maxNum, answer);
}

void permutation(int arr[], int sel[], int len, int count) {
    if(count == N) {
        vector<int> vec;
        for(int i = 0; i < N; i++) {
            vec.push_back(sel[i]);
        }
        solve(vec, len);
        answer = 0;
        vec.clear();
        return;
    }
    
    for(int i = 0; i < W; i++) {
        sel[count] = arr[i];
        permutation(arr, sel, len, count + 1);
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> W >> H;
        initMatrix(W, H);
        int arr[W], sel[W];
//        cout << endl;
        for(int i = 0; i < W; i++) arr[i] = i + 1;
        for(int i = 0; i < W; i++) sel[i] = 0;
        permutation(arr, sel, W, 0);
        cout << "#" << test_case << " " << brick - maxNum << endl;
//        cout << "brick = " << brick << ", num = " << maxNum << endl;
        answer = 0;
        maxNum = 0;
        brick = 0;
    }
    
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}



//#include <iostream>
//#include <vector>
//using namespace std;
//int N, W, H;
//int matrix[15][12];
//int copyM[15][12];
//int answer = 0, maxNum = 0, brick = 0;;
//void initMatrix(int w, int h) {
//    for(int i = 0; i < 15; i++) {
//        for(int j = 0; j < 12; j++) matrix[i][j] = 0;
//    }
//
//    for(int i = 0; i < h; i++) {
//        for(int j = 0; j < w; j++) cin >> matrix[i][j];
//    }
//
//    for(int i = 0; i < h; i++) {
//        for(int j = 0; j < w; j++) {
//            if(matrix[i][j] == 1) brick++;
//        }
//    }
//}
//
//void reMatrix() {
//    for(int i = 0; i < W; i++) {
//        for(int j = H - 1; j >= 0; j--) {
//            if(copyM[j][i] == 0) {
//                int temp = j;
//                while(true) {
//                    if(copyM[temp][i] != 0) {
//                        swap(copyM[j][i], copyM[temp][i]);
//                        break;
//                    }
//                    temp--;
//                    if(temp == -1) break;
//                }
//            }
//        }
//    }
//
////    for(int i = 0; i < H; i++) {
////        for(int j = 0; j < W; j++) cout << copyM[i][j];
////        cout << endl;
////    }
////    cout << endl;
//}
//
//void boom(int x, int y, int count) {
////    cout << "x : " << x << ", y : " << y << ", count : " << count << endl;
//    copyM[x][y] = 0;
//    answer++;
//    for(int i = 1; i <= count; i++) { // 오
//        if(y + i >= W) break;
//        if(copyM[x][y + i] == 0) continue;
//        if(copyM[x][y + i] == 1) {
//            copyM[x][y + i] = 0;
//            answer++;
//        } else {
//            boom(x, y + i, copyM[x][y + i] - 1);
//        }
//    }
//    for(int i = 1; i <= count; i++) { // 오
//        if(y - i < 0) break;
//        if(copyM[x][y - i] == 0) continue;
//        if(copyM[x][y - i] == 1) {
//            copyM[x][y - i] = 0;
//            answer++;
//        } else boom(x, y - i, copyM[x][y - i] - 1);
//    }
//    for(int i = 1; i <= count; i++) { // 오
//        if(x + i >= W) break;
//        if(copyM[x + i][y] == 0) continue;
//        if(copyM[x + i][y] == 1) {
//            copyM[x + i][y] = 0;
//            answer++;
//        } else {
//            boom(x + i, y, copyM[x + i][y] - 1);
//        }
//    }
//    for(int i = 1; i <= count; i++) { // 오
//        if(x - i < 0) break;
//        if(copyM[x - i][y] == 0) continue;
//        if(copyM[x - i][y] == 1) {
//            copyM[x - i][y] = 0;
//            answer++;
//        } else {
//            boom(x - i, y, copyM[x - i][y] - 1);
//        }
//    }
//}
//
//void solve(vector<int> vec, int len) {
//    for(int i = 0; i < 15; i++) {
//        for(int j = 0; j < 12; j++) copyM[i][j] = matrix[i][j];
//    }
////    cout << vec[0] << " " << vec[1] << " " << vec[2];
//    for(auto item : vec) {
//        int target = item;
//        for(int i = 0; i <= H - 1; i++) {
////            cout << "I : " << i << " target : " << target << endl;
//            int numberis = copyM[i][target];
//            if(numberis != 0) {
//                boom(i, target, numberis - 1);
//                reMatrix();
//                break;
//            }
//        }
//    }
////    cout << "answer : " << answer << endl;
//    maxNum = max(maxNum, answer);
//}
//
//void permutation(int arr[], int select[], int len, int count) {
//    if(count == N) { //순열부터 다시...
//        vector<int> vec;
//        for(int i = 0; i < N; i++) {
//            vec.push_back(select[i]);
////            cout << select[i] << " ";
//        }
////        cout << endl;
//        solve(vec, len);
//        answer = 0;
//        vec.clear();
//        return;
//    }
//
//    for(int i = 0; i < W; i++) {
//        select[count] = arr[i];
//        permutation(arr, select, len, count + 1);
//    }
//}
//
//int main(int argc, char** argv)
//{
//    int test_case;
//    int T;
//    cin >> T;
//
//    for(test_case = 1; test_case <= T; ++test_case) {
//        cin >> N >> W >> H;
//        initMatrix(W, H);
//        int arr[W], select[W];
//        for(int i = 1; i <= W; i++) arr[i] = i;
//        permutation(arr, select, W, 0);
//        cout << "#" << test_case << " " << brick - maxNum << endl;
//        cout << "brick = " << brick << ", num = " << maxNum << endl;
//        answer = 0;
//        maxNum = 0;
//    }
//
//    return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}
