#include<iostream>
using namespace std;
pair<int, int> matrix[352][352];
int check[352][352];
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

void init() {
    for(int i = 0; i < 352; i++) {
        for(int j = 0; j < 352; j++) {
            matrix[i][j] = make_pair(-2, -2);
            check[i][j] = 0;
        }
    }
}

void input(int N, int M) {
    int point;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> point;
            if(point != 0) {
                matrix[151 + i][151 + j] = make_pair(point, point);
                check[151 + i][151 + j] = 1;
            }
        }
    }
}

void printM(int N, int M) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) cout << matrix[151 + i][151 + j].first;
        cout << endl;
    }
}

void checkM(int time) {
    for(int i = 0; i < 352; i++) {
        for(int j = 0; j < 352; j++) matrix[i][j].first--;
    }
    for(int i = 1; i < 351; i++) {
        for(int j = 1; j < 351; j++) {
            if(matrix[i][j].first == -1) {
                if(matrix[i][j].second != 1 && check[i][j] != 3) {
                    matrix[i][j].first += matrix[i][j].second - 1;
                    check[i][j] = 3;
                }
                for(int k = 0; k < 4; k++) {
                    if(check[i + x[k]][j + y[k]] == 0) {
                        check[i + x[k]][j + y[k]] = time;
                        matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
                    } else if(check[i + x[k]][j + y[k]] == time) {
                        if(matrix[i][j].second > matrix[i + x[k]][j + y[k]].second)
                            matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second,matrix[i][j].second);
                    }
                    
                }
            }
        }
    }

//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            if(check[i][j] == 2) check[i][j] = 1;
//        }
//    }
}

int findAnswer() {
    int answer = 0;
    for(int i = 0; i < 352; i++) {
        for(int j = 0; j < 352; j++) {
            if(matrix[i][j].first >= 0) answer++;
        }
    }
    return answer;
}

int solve(int K, int time) {
    while(true) {
        time++;
//        update();
        checkM(time);
        if(time == K) return findAnswer();
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;

    for(int i = 0; i < testCase; i++) {
        init();
        int N, M, K;
        cin >> N >> M >> K;
        input(N, M);
//        printM(N, M);
        cout << "#" << i + 1 << " " << solve(K, 0) << endl;
    }

    return 0;
}

//#include<iostream>
//using namespace std;
//pair<int, int> matrix[352][352];
//int check[352][352];
//int x[4] = {0, 0, 1, -1};
//int y[4] = {1, -1, 0, 0};
//
//void init() {
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            matrix[i][j] = make_pair(-2, -2);
//            check[i][j] = 0;
//        }
//    }
//}
//
//void input(int N, int M) {
//    int point;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> point;
//            if(point != 0) {
//                matrix[151 + i][151 + j] = make_pair(point, point);
//                check[151 + i][151 + j] = 1;
//            }
//        }
//    }
//}
//
//void printM(int N, int M) {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) cout << matrix[151 + i][151 + j].first;
//        cout << endl;
//    }
//}
//
////void update() {
////    for(int i = 0; i < 352; i++) {
////        for(int j = 0; j < 352; j++) matrix[i][j].first--;
////    }
////}
//
//void checkM(int time) { // 벡터에 담아서?
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) matrix[i][j].first--;
//    }
//    for(int i = 1; i < 351; i++) {
//        for(int j = 1; j < 351; j++) {
////            matrix[i][j].first--;
//            if(matrix[i][j].first == -1) {
//                if(matrix[i][j].second != 1 && check[i][j] != 3) {
//                    matrix[i][j].first += matrix[i][j].second - 1;
//                    check[i][j] = 3;
//                }
//                for(int k = 0; k < 4; k++) {
////                    if(check[i + x[k]][j + y[k]] != 1) {
////                        if(check[i + x[k]][j + y[k]] == 2) {
////                            if(matrix[i][j].second > matrix[i + x[k]][j + y[k]].second)
////                                matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
////                        } else if(check[i + x[k]][j + y[k]] == 0) {
////                            check[i + x[k]][j + y[k]] = 2;
////                            matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
////                        }
////                    }
//                    if(check[i + x[k]][j + y[k]] == 0) {
//                        check[i + x[k]][j + y[k]] = time;
//                        matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
//                    } else if(check[i + x[k]][j + y[k]] == time) {
//                        if(matrix[i][j].second > matrix[i + x[k]][j + y[k]].second)
//                            matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second,matrix[i][j].second);
//                    }
//
//                }
//            }
//        }
//    }
//
////    for(int i = 0; i < 352; i++) {
////        for(int j = 0; j < 352; j++) {
////            if(check[i][j] == 2) check[i][j] = 1;
////        }
////    }
//}
//
//int findAnswer() {
//    int answer = 0;
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            if(matrix[i][j].first >= 0) answer++;
//        }
//    }
//    return answer;
//}
//
//int solve(int K, int time) {
//    while(true) {
//        time++;
////        update();
//        checkM(time);
//        if(time == K) return findAnswer();
//    }
//}
//
//int main(int argc, char** argv)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    int testCase;
//    cin >> testCase;
//
//    for(int i = 0; i < testCase; i++) {
//        init();
//        int N, M, K;
//        cin >> N >> M >> K;
//        input(N, M);
////        printM(N, M);
//        cout << "#" << i + 1 << " " << solve(K, 0) << endl;
//    }
//
//    return 0;
//}

//#include<iostream> // 41개에서 시간초과
//using namespace std;
//pair<int, int> matrix[352][352];
//int check[352][352];
//int x[4] = {0, 0, 1, -1};
//int y[4] = {1, -1, 0, 0};
//
//void init() {
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            matrix[i][j] = make_pair(-2, -2);
//            check[i][j] = 0;
//        }
//    }
//}
//
//void input(int N, int M) {
//    int point;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> point;
//            if(point != 0) {
//                matrix[151 + i][151 + j] = make_pair(point, point);
//                check[151 + i][151 + j] = 1;
//            }
//        }
//    }
//}
//
//void printM(int N, int M) {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) cout << matrix[151 + i][151 + j].first;
//        cout << endl;
//    }
//}
//
//void update() {
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) matrix[i][j].first--;
//    }
//}
//
//void checkM() {
//    for(int i = 1; i < 351; i++) {
//        for(int j = 1; j < 351; j++) {
//            if(matrix[i][j].first == -1) {
//                if(matrix[i][j].second != 1 && check[i][j] != 3) {
//                    matrix[i][j].first += matrix[i][j].second - 1;
//                    check[i][j] = 3;
//                }
//                for(int k = 0; k < 4; k++) {
//                    if(check[i + x[k]][j + y[k]] != 1) {
//                        if(check[i + x[k]][j + y[k]] == 2) {
//                            if(matrix[i][j].second > matrix[i + x[k]][j + y[k]].second)
//                                matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
//                        } else if(check[i + x[k]][j + y[k]] == 0) {
//                            check[i + x[k]][j + y[k]] = 2;
//                            matrix[i + x[k]][j + y[k]] = make_pair(matrix[i][j].second, matrix[i][j].second);
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            if(check[i][j] == 2) check[i][j] = 1;
//        }
//    }
//}
//
//int findAnswer() {
//    int answer = 0;
//    for(int i = 0; i < 352; i++) {
//        for(int j = 0; j < 352; j++) {
//            if(matrix[i][j].first >= 0) answer++;
//        }
//    }
//    return answer;
//}
//
//int solve(int K, int time) {
//    while(true) {
//        time++;
//        update();
//        checkM();
//        if(time == K) return findAnswer();
//    }
//}
//
//int main(int argc, char** argv)
//{
//    ios::sync_with_stdio(false);
//    cin.tie(NULL); cout.tie(NULL);
//    int testCase;
//    cin >> testCase;
//
//    for(int i = 0; i < testCase; i++) {
//        init();
//        int N, M, K;
//        cin >> N >> M >> K;
//        input(N, M);
////        printM(N, M);
//        cout << "#" << i + 1 << " " << solve(K, 0) << endl;
//    }
//
//    return 0;
//}
//
