#include <cstdio>
#include <cstring>

char s[10];
int m, a, ans = 0;

int main(void)
{
	scanf("%d", &m);


	while (m--) {
		scanf("%s %d", s, &a);
		if (!strcmp(s, "add")) ans |= (1 << a);
		else if (!strcmp(s, "remove")) ans &= ~(1 << a);
		else if (!strcmp(s, "check")) ans&(1 << a) ? puts("1") : puts("0");
		else if (!strcmp(s, "toggle")) ans ^= (1 << a);
		else if (!strcmp(s, "all")) ans |= ~0;
		else ans &= 0;
	}


	return 0;
}