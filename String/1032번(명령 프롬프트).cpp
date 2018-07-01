#include <cstdio>
#include <cstring>

int n;
char s[50], e[50];

int main(void)
{
	scanf("%d%s", &n, s);
	int len = strlen(s);

	for (int i = 0; i < n - 1; i++) {
		scanf("%s", e);
		for (int j = 0; j < len; j++) {
			if (s[j] != e[j]) s[j] = '!';
		}
	}
	for (int i = 0; i < len; i++) s[i] == '!' ? printf("?") : printf("%c", s[i]);
	return 0;
}