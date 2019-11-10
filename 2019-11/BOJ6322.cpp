#include <cstdio>
#include <cmath>
using namespace std;

int a,b,c;

int main(void)
{
	int num = 1;
	while(true){
		scanf("%d%d%d",&a,&b,&c);
		if(!a && !b && !c) break;
		double ans = 0.0;
		if(a == -1) ans = c*c - b*b;
		else if(b == -1) ans = c*c - a*a;
		else if(c == -1) ans = a*a + b*b;
		printf("Triangle #%d\n",num++);
		if(ans <= 0) puts("Impossible.");
		else {
			a == -1 ? printf("a = ") : (b == -1 ? printf("b = ") : printf("c = "));
			printf("%.3lf\n", sqrt(ans));
		}
		puts("");
	}
	return 0;
}