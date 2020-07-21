#include <stack>
#include <bitset>

int solution(int N) {
    stack<int> st;
    string binary = bitset<32>(N).to_string();
    int count = 0, maxNum = 0;
    int binaryLength = binary.length();
    for(int i = 0; i < binaryLength; i++) {
        if(st.empty()) {
            if(binary[i] == '1') st.push(1);
        } else {
             if(binary[i] == '1') {
                 maxNum = max(maxNum, count);
                 count = 0;
             } else count++;
        }
    }
    return maxNum;
}
