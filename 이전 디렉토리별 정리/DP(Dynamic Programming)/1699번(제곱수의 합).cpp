#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int dp[100005], n, z;
vector<int> sq;
const int INF = 2100000000;
bool s;


int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) dp[i] = INF;

	for (int i = 1; i <= n; i++) {
		if (!fmod(sqrt(i),1.0)) {
			dp[i] = 1; sq.push_back(i);
			printf("%d : %d\n", i, dp[i]);
		}
		else {
			printf("-------------------------------\n");
			for (int j = 0; j < sq.size(); j++) {
				dp[i] = min(dp[i], dp[sq[j]] + dp[i - sq[j]]);
				printf("%d : %d\n", i, dp[i]);
			}
			printf("-------------------------------\n");
		
		}
	}

	printf("%d", dp[n]);
	return 0;
}