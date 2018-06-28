#include <cstdio>

char word[100];

int main(void)
{
	scanf("%s", word);
	int i = 0;
	while (word[i]) i++;
	printf("%d", i);
	return 0;
}