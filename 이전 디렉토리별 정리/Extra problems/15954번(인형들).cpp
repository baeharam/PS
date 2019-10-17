#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k;
double doll[501];

double sd(int s, int e, int num)
{
    double sum = 0.0;
    for(int i=s; i<=e; i++) sum+=doll[i];

    double avg = sum/num;
    sum = 0.0;
    for(int i=s; i<=e; i++) {
        sum+=(doll[i]-avg)*(doll[i]-avg);
    }

    double ans = sum / (double)num;
    return sqrt(ans);
}

int main(void)
{
    scanf("%d%d",&n, &k);
    for(int i=1; i<=n; i++) scanf("%lf",&doll[i]);

    double ans = (double)2100000000;
    int i=1;
    while(i<=n-k+1){
        for(int j=k; j<=n-i+1; j++)
            ans = min(ans, sd(i, i+j-1, j));
        i++;
    }
    printf("%.11f\n",ans);
    return 0;
}