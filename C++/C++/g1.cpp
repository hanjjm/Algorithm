#include <string>
using namespace std;
int month[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
string day[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};

string solution(int a, int b) {
    return day[(month[a - 1] + b - 1) % 7];
}
