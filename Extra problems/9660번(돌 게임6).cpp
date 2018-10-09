#include <cstdio>

unsigned long long n;

int main(void)
{
    scanf("%lld",&n);

    if(n%7==0 || (n+5)%7==0) printf("CY");
    else printf("SK");

    return 0;
}