#include <cstdio>
#include <algorithm>
using namespace std;

int dp[201], koi[201], n, ans;

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&koi[i]);
        dp[i] = 1;
    }


    for(int i=2; i<=n; i++){
        for(int j=i-1; j>=1; j--){
            if(koi[j]<koi[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    printf("%d\n", n - ans);
    return 0;
}