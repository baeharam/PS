#include <cstdio>
#include <algorithm>

int a[1001],d1[1001],d2[1001],n,m1,m2;

int main(void)
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        d1[i]=1;
        d2[i]=1;
    }


    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            if(a[i]>a[j] && d1[j]+1>d1[i])
                d1[i] = d1[j]+1;
        }
    }

    for(int i=n-1; i>=1; i--){
        for(int j=n; j>i; j--){
            if(a[i]>a[j] && d2[j]+1>d2[i])
                d2[i] = d2[j]+1;
        }
    }

    int max = 0;
    for(int i=1; i<=n; i++) {
        max = std::max(max, d1[i]+d2[i]);
    }


    printf("%d\n", max-1);

    return 0;
}