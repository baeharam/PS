#include <cstdio>
#include <algorithm>

int tc,n,ans,tong[10000],retong[10000];

inline int difference(int a, int b){
    return a>b ? a-b : b-a;
}

int main(void)
{
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d", &tong[i]);
        std::sort(tong, tong+n);
        
        retong[n/2] = tong[n-1];
        for(int i=n-2, j=1; i>=0; j++) {
            if(n/2+j < n && i>=0) {
                retong[n/2+j] = tong[i];
                i--;
            }
            if(n/2-j >= 0 && i>=0) {
                retong[n/2-j] = tong[i];
                i--;
            }
        }

        ans = difference(retong[0], retong[n-1]);
        for(int i=1; i<n; i++) {
            int diff = difference(retong[i], retong[i-1]);
            if(diff>ans) ans = diff; 
        }

        printf("%d\n", ans);
    }
}