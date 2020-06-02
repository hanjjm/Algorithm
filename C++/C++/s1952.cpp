#include <iostream>
using namespace std;
int day, month, threeMonth, year;
int table[12], DP[12];

void downgrade() {
    for(int i = 0; i < 12; i++) table[i] = min(table[i] * day, month);
}

void initialDP() {
    DP[0] = table[0];
    DP[1] = table[0] + table[1];
    DP[2] = min(table[0] + table[1] + table[2], threeMonth);
}

int solve() {
    for(int i = 3; i < 12; i++) {
        DP[i] = min(DP[i - 1] + table[i], DP[i - 3] + threeMonth);
    }
    if(DP[11] > year) return year;
    else return DP[11];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int testCase;
    cin >> testCase;
    for(int i = 1; i <= testCase; i++) {
        cin >> day >> month >> threeMonth >> year;
        for(int j = 0; j < 12; j++) {
            cin >> table[j];
            DP[j] = 0;
        }
        downgrade();
        initialDP();
        cout << "#" << i << " " << solve() << endl;
    }
}
