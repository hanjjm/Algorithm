#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    int x, y, form;
} Point;

vector<vector<int>> bf;
vector<Point> point;

bool compare(Point a, Point b) {
    if(a.x < b.x) return true;
    else if(a.x == b.x) {
        if(a.y < b.y) return true;
        else if(a.y == b.y) {
            if(a.form == 0) return true;
            else return false;
        } else return false;
    } else return false;
}

bool bfCheck(int n) {
    for(int i = 0; i < point.size(); i++) {
        bool flag = false;

        if(point[i].form == 0) { // 기둥
            if(point[i].x >= n + 1 || point[i].y >= n) return false;
            if(point[i].y == 0) flag = true;
            for(int j = 0; j < point.size(); j++) {
                if(point[i].x == point[j].x && point[i].y - 1 == point[j].y && point[j].form == 0) flag = true; // 밑에
                if(point[i].x - 1 == point[j].x && point[i].y == point[j].y && point[j].form == 1) flag = true;
                if(point[i].x == point[j].x && point[i].y == point[j].y && point[j].form == 1) flag = true;
            }
        } else if(point[i].form == 1) {
            if(point[i].x >= n || point[i].y >= n + 1) return false;
            int count = 0;
            for(int j = 0; j < point.size(); j++) {
                if(point[i].x == point[j].x && point[i].y - 1 == point[j].y && point[j].form == 0) flag = true;
                if(point[i].x + 1 == point[j].x && point[i].y - 1 == point[j].y && point[j].form == 0) flag = true;
                if(point[i].x - 1 == point[j].x && point[i].y == point[j].y && point[j].form == 1) count++;
                if(point[i].x + 1 == point[j].x && point[i].y == point[j].y && point[j].form == 1) count++;
            }
            if(count >= 2) flag = true;
        }
        
        if(!flag) return false;
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int length = build_frame.size();
    bf = build_frame; // 이름이 너무 길다..
    
    for(int i = 0; i < length; i++) {
        if(bf[i][3] == 1) { // 설치
            point.push_back({bf[i][0], bf[i][1], bf[i][2]});
            if(!bfCheck(n)) point.erase(point.begin() + point.size() - 1);
        } else { // 삭제
            bool flag = false;
            for(int j = 0; j < point.size(); j++) {
                if(point[j].x == bf[i][0] && point[j].y == bf[i][1] && point[j].form == bf[i][2]) {
                    point.erase(point.begin() + j); // 일단 삭제해보자
                    flag = true;
                    break;
                }
            }
            if(!bfCheck(n) && flag) point.push_back({bf[i][0], bf[i][1], bf[i][2]});
        }
    }
    
    sort(point.begin(), point.end(), compare);
    
    for(int i = 0; i < point.size(); i++) {
        // cout << point[i].x << " " << point[i].y << " " << point[i].form << endl;
        vector<int> temp;
        temp.push_back(point[i].x);
        temp.push_back(point[i].y);
        temp.push_back(point[i].form);
        answer.push_back(temp);
    }
    
    return answer;
}
