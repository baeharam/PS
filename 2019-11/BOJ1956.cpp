#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxv = 400;
const ll INF = 2e17;

int V,E,a,b,c;
int cost[maxv + 1][maxv + 1];
ll dp[maxv + 1][maxv + 1];

int main(void)
{
    cin >> V >> E;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        cost[a][b] = c;
    }

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            dp[i][j] = (ll) (cost[i][j] ? cost[i][j] : INF);
        }
    }

    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    ll ans = INF;
    for(int i=1; i<=V; i++){
        if(dp[i][i] == INF) continue;
        ans = min(ans, dp[i][i]);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}