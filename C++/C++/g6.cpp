#include <iostream>
using namespace std;
int diamondLength;
int diamond[200][200];

void inputNum() {
    for(int i = 0; i < 200; i++)
        for(int j= 0; j < 200; j++) diamond[i][j] = 0;
    
    int index = 1, flag = 0;
    for(int i = 0; i < 2 * diamondLength - 1; i++) {
        for(int j = 0; j < index; j++) {
            cin >> diamond[i][j];
        }
        if(flag == 0) index++;
        else index--;
        if(index == diamondLength + 1) {
            index -= 2;
            flag = 1;
        }
    }
}

void solve() {
    int DP[200][200];
    for(int i = 0; i < 200; i++)
        for(int j= 0; j < 200; j++) DP[i][j] = 0;
    DP[0][0] = diamond[0][0];
    DP[1][0] = diamond[1][0] + diamond[0][0];
    DP[1][1] = diamond[1][1] + diamond[0][0];
    
    for(int i = 2; i < diamondLength; i++) {
        DP[i][0] = DP[i - 1][0] + diamond[i][0];
        DP[i][i] = DP[i - 1][i - 1] + diamond[i][i];
        for(int j = 1; j < i; j++) {
            DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + diamond[i][j];
        }
    }
    
    for(int i = diamondLength; i < 2 * diamondLength - 1; i++) {
        for(int j = 0; j < 2 * diamondLength - i - 1; j++) {
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j + 1]) + diamond[i][j];
        }
    }
    
    cout << DP[2 * diamondLength - 2][0];
}

int main() {
    cin >> diamondLength;
    inputNum();
    solve();
    return 0;
}
