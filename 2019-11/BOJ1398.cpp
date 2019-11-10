#include <cstdio>
#include <algorithm>
using namespace std;

using ll = long long;
int T;
int dp[105];
const int coin[4] = { 0, 1, 10, 25 };


int main(void)
{
    scanf("%d",&T);
    for(int i=1; i<=99; i++){
        dp[i] = 2e9;
        for(int j=1; j<=3; j++){
            if(i - coin[j] < 0) break;
            dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    while(T--){
        ll N;
        int ans = 0;
        scanf("%lld",&N);
        ll mod = 100000000000000;
        while(N){
            ans += dp[N / mod];
            N %= mod;
            mod /= 100LL;        
        }
        printf("%d\n", ans);
    }
    return 0;
}
