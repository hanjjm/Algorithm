#include <iostream>
#include <vector>
using namespace std;
int matrix[12][12] = {0, };
vector<int> a, b, x, y, C, P;

void walk(int time) {
    int direction;
    for(int i = 0; i < time; i++) {
        cin >> direction;
        a.push_back(direction);
    }
    for(int i = 0; i < time; i++) {
        cin >> direction;
        b.push_back(direction);
    }
}

pair<int, int> nextAStep(pair<int, int> nowCoor, int time) {
    pair<int, int> step;
    if(a[time] == 0) {
        step = nowCoor;
    } else if(a[time] == 1) {
        step.first = nowCoor.first - 1;
        step.first = nowCoor.second;
    } else if(a[time] == 2) {
        step.first = nowCoor.first;
        step.first = nowCoor.second + 1;
    } else if(a[time] == 3) {
        step.first = nowCoor.first + 1;
        step.first = nowCoor.second;
    } else if(a[time] == 4) {
        step.first = nowCoor.first;
        step.first = nowCoor.second - 1;
    }
    return step;
}

pair<int, int> nextBStep(pair<int, int> nowCoor, int time) {
    pair<int, int> step;
    if(b[time] == 0) {
        step = nowCoor;
    } else if(b[time] == 1) {
        step.first = nowCoor.first - 1;
        step.first = nowCoor.second;
    } else if(b[time] == 2) {
        step.first = nowCoor.first;
        step.first = nowCoor.second + 1;
    } else if(b[time] == 3) {
        step.first = nowCoor.first + 1;
        step.first = nowCoor.second;
    } else if(b[time] == 4) {
        step.first = nowCoor.first;
        step.first = nowCoor.second - 1;
    }
    return step;
}
void inner() {
    
}

void solve(int time, int number) {
    int aMax = 0, bMax = 0, aTemp = 0, bTemp = 0;
//    cout << "@@@" << endl;
//    for(auto item : x) cout << item << " ";
//    cout << endl << time << endl;
    pair<int, int> a_next = make_pair(1, 1), b_next = make_pair(10, 10);
    for(int i = 0; i < time; i++) {
        cout << "x : " << a_next.first << ", y : " << a_next.second << endl;
        aTemp = 0; bTemp = 0;
        for(int j = 0; j < number; j++) {
//            cout << abs(a_next.first - x[j]) + abs(a_next.second - y[j]) << " < " << C[j] << endl;
            if(abs(a_next.first - a[j]) + abs(a_next.second - a[j]) <= C[j]) {
                aTemp = max(aTemp, P[j]);
            }
            if(abs(b_next.first - b[j]) + abs(b_next.second - b[j]) <= C[j]) {
                bTemp = max(bTemp, P[j]);
            }
            
        }
        aMax += aTemp;
        bMax += bTemp;
        a_next = nextAStep(a_next, i);
        b_next = nextBStep(b_next, i);
    }
//    cout << "aMax : " << aMax << ", bMax : " << bMax << endl;
    cout << aMax + bMax << endl;
}

void battery(int number, int time) {
    int _y, _x, _C, _P;
    for(int i = 0; i < number; i++) {
        cin >> _y >> _x >> _C >> _P;
        x.push_back(_y); y.push_back(_x);
        C.push_back(_C); P.push_back(_P);
    }
    
    solve(time, number);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case) {
        int M, A;
        cin >> M >> A;
        walk(M);
        battery(A, M);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
