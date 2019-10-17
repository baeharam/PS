#include <cstdio>

char s[100005];
int stick, ans;

int main(void)
{
	scanf("%s", s);

	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '(') {
			if (s[i + 1] == ')') {
				ans += stick;
				i += 1;
			}
			else stick++;
		}
		else {
			stick--;
			ans += 1;
		}
		i++;
	}
	printf("%d", ans);
	return 0;
}