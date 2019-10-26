#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

typedef pair<int,int> pii;
int vi[100000];
vector<pii> aa;

int solution(vector<int> A, vector<int> B) {
    int n = A.size();
    for(int i=0; i<n; i++) aa.push_back({A[i],i});
    sort(aa.begin(),aa.end());
    sort(B.begin(),B.end(),greater<int>());
    int ans = 0;
    for(int i=0; i<n; i++){
        int target = B[i];
        int l = 0, r = n-1, idx = -1;
        while(l <= r){
            int m = (l+r) / 2;
            if(aa[m].first >= target || vi[aa[m].second]) r = m - 1;
            else {
                idx = aa[m].second;
                l = m + 1;
            }
        }
        if(idx != -1){
            ans++;
            vi[idx] = 1;
        }
    }
    return ans;
}