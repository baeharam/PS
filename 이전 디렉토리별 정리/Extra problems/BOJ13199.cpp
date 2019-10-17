#include <cstdio>

int tc,p,m,f,c,coupon,ans;

int main(void)
{
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d%d%d",&p,&m,&f,&c);
        coupon = ((m/p)*c)/f*c;
        coupon += ((m/p)*c)%f;
        while(coupon>=f){
            int q = coupon/f, r = coupon%f;
            coupon = q*c;
            ans+=q;
            coupon+=r;
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}