#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll sq[101][101], sum[101][101], ans;
char parse[102];
int n,m;

ll real_sum(int x1, int y1, int x2, int y2)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
}

int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++){
        scanf("%s", parse);
        for(int j=0; j<m; j++)
            sq[i][j+1] = parse[j]-'0';
    }

    // 미리 부분합들을 구해놓는다.
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++) {
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sq[i][j];
        }
    }

    ll sum1, sum2, sum3;

    // 1번째 경우 : =
    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++) {
            sum1 = real_sum(1,1,i,m);
            sum2 = real_sum(i+1,1,j,m);
            sum3 = real_sum(j+1,1,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    // 2번째 경우 : ||
    for(int i=1; i<=m-2; i++){
        for(int j=i+1; j<=m-1; j++) {
            sum1 = real_sum(1,1,n,i);
            sum2 = real_sum(1,i+1,n,j);
            sum3 = real_sum(1,j+1,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    // 3번째 경우 ㅗ
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=m-1; j++){
            sum1 = real_sum(1,1,i,j);
            sum2 = real_sum(1,j+1,i,m);
            sum3 = real_sum(i+1,1,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    // 4번째 경우 ㅜ
    for(int i=2; i<=n; i++){
        for(int j=1; j<=m-1; j++){
            sum1 = real_sum(1,1,i-1,m);
            sum2 = real_sum(i,1,n,j);
            sum3 = real_sum(i,j+1,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    // 5번째 경우 ㅓ
    for(int i=1; i<=n-1; i++){
        for(int j=1; j<=m-1; j++){
            sum1 = real_sum(1,1,i,j);
            sum2 = real_sum(i+1,1,n,j);
            sum3 = real_sum(1,j+1,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    // 6번째 경우 ㅏ
    for(int i=1; i<=n-1; i++){
        for(int j=m; j>=2; j--){
            sum1 = real_sum(1,j,i,m);
            sum2 = real_sum(1,1,n,j-1);
            sum3 = real_sum(i+1,j,n,m);
            ans = max(ans, sum1*sum2*sum3);
        }
    }

    printf("%lld\n", ans);
    return 0;
}