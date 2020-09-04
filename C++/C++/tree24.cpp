#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> node(10001);

typedef struct{
    int nodeNum, left, right, x, y;
} Node;

typedef struct{
    int left, right;
} Move;

bool compare(vector<int> a, vector<int> b) {
    if(a[1] > b[1]) return true;
    else if(a[1] == b[1]) {
        if(a[0] < b[0]) return true;
        else return false;
    } else return false;
}

Node nodeR[10001];
Move relation[10001];

void makeTree(int nodeNum, vector<vector<int>> nodeinfo) {
    for(int i = 0; i < nodeinfo.size(); i++) {
        cout << nodeR[i + 1].nodeNum << " " <<
        nodeR[i + 1].x << " " <<
        nodeR[i + 1].y << " " <<
        nodeR[i + 1].left << " " <<
        nodeR[i + 1].right << endl;
    }
    
    for(int i = 2; i <= nodeinfo.size(); i++) {
        int parent = nodeNum;
        
        while(true) {
            if(nodeR[i].x < nodeR[parent].x) {
                if(nodeR[parent].left == 0) {
                    nodeR[parent].left = i;
                    break;
                } else parent = nodeR[parent].left;
            } else {
                if(nodeR[parent].right == 0) {
                    nodeR[parent].right = i;
                    break;
                } else parent = nodeR[parent].right;
            }
        }
        
    }
    
}

vector<int> pre;
void preOrder(int num) {
    if(num == 0)  return;
    pre.push_back(num);
    preOrder(relation[num].left);
    preOrder(relation[num].right);
}

vector<int> post;
void postOrder(int num) {
    if(num == 0)  return;
    postOrder(relation[num].left);
    postOrder(relation[num].right);
    post.push_back(num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for(int i = 1; i <= nodeinfo.size(); i++) nodeinfo[i - 1].push_back(i);
    
    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        nodeR[i + 1].nodeNum = nodeinfo[i][2];
        nodeR[i + 1].x = nodeinfo[i][0];
        nodeR[i + 1].y = nodeinfo[i][1];
        nodeR[i + 1].left = 0;
        nodeR[i + 1].right = 0;
    }
    
    makeTree(1, nodeinfo);
    
    for(int i = 1; i <= nodeinfo.size(); i++) {
        relation[nodeR[i].nodeNum].left = nodeR[nodeR[i].left].nodeNum;
        relation[nodeR[i].nodeNum].right = nodeR[nodeR[i].right].nodeNum;
    }
    
    preOrder(nodeR[1].nodeNum);
    postOrder(nodeR[1].nodeNum);
    
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}
