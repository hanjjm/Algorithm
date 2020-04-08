#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    
    for(int width = 3; width < 5000; width++) {
        for(int height = 3; height <= width; height++) {
            int Bcheck = 2 * width + 2 * (height - 2) ;
            if(Bcheck == brown && width * height == brown + red) {
                answer.push_back(width); answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}
