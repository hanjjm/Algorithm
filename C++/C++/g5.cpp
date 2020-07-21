#include <algorithm>

int solution(vector<int> &A) {
    int vectorLength = A.size();
    if(vectorLength == 0) return 1;
    int compareNum = 1;
    sort(A.begin(), A.end());
    
    for(int i = 0; i < vectorLength; i++) {
        if(A[i] != compareNum) return compareNum;
        compareNum++;
    }
    return compareNum;
}
