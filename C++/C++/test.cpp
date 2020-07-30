#include <iostream>
using namespace std;
int N, K, answer = 0;
int arr[1000], check[1000] = {0, };

void combi(int index, int count) {
    if(count == K) {
        int plus = 0;
        for(int i = 0; i < N; i++) {
            if(check[i] == 1) {
                plus += arr[i];
            }
        }
        if(plus % N == 0) answer++;
        return;
    }
    
    for(int i = index; i < N; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            combi(i, count + 1);
            check[i] = 0;
        }
    }
}

int main() {
    cin >> N >> K;
    for(int i = 0; i < 1000; i++) arr[i] = i;
    combi(0, 0);
    cout << answer;
    return 0;
}
