#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[10001],B[10001],IDX[10001],C[10001];
vector<int> tree;
vector<pair<int,int> > ans;

void u(int node, int s, int e, int index, int diff)
{
    if(e<index || index<s) return;
    if(s==e) {
        tree[node] += diff;
        return;
    }
    tree[node] += diff;
    u(node*2,s,(s+e)/2,index,diff);
    u(node*2+1,(s+e)/2+1,e,index,diff);
}

int q(int node, int s, int e, int l, int r)
{
    if(e<l || r<s) return 0;
    if(l<=s && e<=r) return tree[node];
    return q(node*2,s,(s+e)/2,l,r)+q(node*2+1,(s+e)/2+1,e,l,r);
}

int main(void)
{
    scanf("%d",&N);

    for(int i=1; i<=N; i++) scanf("%d",&A[i]);
    for(int i=1; i<=N; i++) scanf("%d",&B[i]);

    for(int i=1; i<=N; i++) IDX[B[i]] = i;

    tree.resize(4*N,0);

    int mv = 0;
    for(int i=1; i<=N; i++) {
        int bidx = IDX[A[i]];
        int ret = q(1,1,N,1,bidx-1);
        if(ret+1 >= mv) {
            if(C[ret+1]) u(1,1,N,IDX[C[ret+1]],-1);
            C[ret+1] = A[i];
            mv = ret+1;
            u(1,1,N,bidx,1);
        }
    }

    sort(C+1,C+mv+1);

    printf("%d\n",mv);
    for(int i=1; i<=mv; i++) printf("%d ",C[i]);
    puts("");

    return 0;
}