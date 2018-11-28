#include <cstdio>
#include <algorithm>
using namespace std;

int n,c,l_b,u_b,ans;
int house[200001],dist[200001];

int main(void)
{
    scanf("%d%d",&n,&c);
    for(int i=1; i<=n; i++) scanf("%d",&house[i]);
    sort(house+1,house+n+1);

    for(int i=2,j=1; i<=n; i++,j++) dist[j] = house[i]-house[i-1]; 
    for(int i=2; i<=n-1; i++) dist[i]+=dist[i-1];

    l_b = 1, u_b = house[n]-house[1];
    c--;
    while(l_b<=u_b){
        int k = (l_b+u_b)/2;
        int i = 1, modem = 0, before = 0;
        while(i<=n-1){
            if(dist[i]-dist[before]>=k) {
                before = i;
                modem++;
            }
            if(modem==c) break;
            i++;
        }
        if(modem<c) u_b = k-1;
        else {
            ans = max(ans, k);
            l_b = k+1;
        }
    }

    printf("%d",ans);

    return 0;
}