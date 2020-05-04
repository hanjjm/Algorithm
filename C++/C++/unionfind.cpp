#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<long long, long long> room;

long long find(long long next) {
    if(room[next] == 0) return next;
    else return find(room[next]);
    
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    int len = room_number.size();
    for(int i = 0; i < len; i++) {
        long long nextRoom = find(room_number[i]);
        answer.push_back(nextRoom);
        room[nextRoom] = find(nextRoom + 1);
    }
    
    return answer;
}
