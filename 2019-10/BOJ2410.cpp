#include <cstdio>
#include <cmath>
using namespace std;

// https://casterian.net/archives/176 설명 공부

const int mod = (int)1e9;
int dp[1000005][21];
int n;

int main(void)
{
  scanf("%d",&n);
  int limit = (int)floor(log2(n));
  // dp[i][0] = i를 2^0으로 나타내는 경우, 즉 1만 사용하는 경우
  for(int i=1; i<=n; i++) dp[i][0] = 1;
  // dp[0][i] = 0을 2^i로 나타내는 경우, 정확히는 2의 멱수가 새롭게 등장하는 경우
  for(int i=1; i<=limit; i++) dp[0][i] = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=limit; j++){
      int p = i - (1 << j);
      dp[i][j] = (dp[i][j-1] + (p < 0 ? 0 : dp[p][j])) % mod;
    }
  }
  printf("%d\n",dp[n][limit]);
  return 0;
}