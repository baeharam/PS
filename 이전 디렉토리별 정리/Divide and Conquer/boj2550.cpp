#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int A[10001],B[10001],L[10001];
vector<int> lis,ans;
vector<int>::iterator it;

int main(void)
{  
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d",&A[i]);
    for(int i=1; i<=N; i++) {
        int val;
        scanf("%d",&val);
        B[val] = i;
    }

    lis.push_back(B[A[1]]);
    L[1] = 1;

    int max_lis_idx = 1, max_a_idx = 1,lis_idx = 1;

    for(int i=2; i<=N; i++){
        int bidx = B[A[i]];
        it = lower_bound(lis.begin(),lis.end(),bidx);
        if(it==lis.end()) {
            lis_idx = lis.size()+1;
            lis.push_back(bidx);
        } else {
            lis_idx = it-lis.begin()+1;
            *it = bidx;
        }
        L[i] = lis_idx;

        if(lis_idx >= max_lis_idx){
            max_lis_idx = lis_idx;
            max_a_idx = i;
        }
    }

    for(int i=max_a_idx,k=max_lis_idx; i>=1; i--){
        if(L[i]==k && B[A[i]]<=B[A[max_a_idx]]){
            ans.push_back(A[i]);
            k--;
        }
    }

    sort(ans.begin(),ans.end());

    printf("%lu\n",ans.size());
    for(int _ans : ans) printf("%d ",_ans);
    puts("");
    return 0;
}