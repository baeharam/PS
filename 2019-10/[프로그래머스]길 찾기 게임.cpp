#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct info {
    int x,y,idx;
    bool operator<(const info& rhs) const {
        if(x == rhs.x) return y < rhs.y;
        return x > rhs.x;
    }
};
vector<info> xx;
vector<int> pre,post;

void preorder(int ys, int ye, info cur, int node){
    pre.push_back(cur.idx+1);
    int my = cur.y;
    for(int i=0; i<xx.size(); i++){
        if(xx[i].y >= ys && xx[i].y < my){
            preorder(ys,my-1,xx[i],node*2);
            break;
        }
    }
    for(int i=0; i<xx.size(); i++){
        if(xx[i].y > my && xx[i].y <= ye){
            preorder(my+1,ye,xx[i],node*2+1);
            break;
        }
    }
}

void postorder(int ys, int ye, info cur, int node){
    int my = cur.y;
    for(int i=0; i<xx.size(); i++){
        if(xx[i].y >= ys && xx[i].y < my){
            postorder(ys,my-1,xx[i],node*2);
            break;
        }
    }
    for(int i=0; i<xx.size(); i++){
        if(xx[i].y > my && xx[i].y <= ye){
            postorder(my+1,ye,xx[i],node*2+1);
            break;
        }
    }
    post.push_back(cur.idx+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int minY = 2e9, maxY = 0;
    for(int i=0; i<nodeinfo.size(); i++){
        xx.push_back((info){nodeinfo[i][1],nodeinfo[i][0],i});
        minY = min(minY,nodeinfo[i][0]);
        maxY = max(maxY,nodeinfo[i][0]);
    }
    sort(xx.begin(),xx.end());
    preorder(minY,maxY,xx[0],1);
    postorder(minY,maxY,xx[0],1);
    vector<vector<int>> ans;
    ans.push_back(pre); ans.push_back(post);
    return ans;
}