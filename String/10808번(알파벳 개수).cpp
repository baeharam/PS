#include <cstdio>
char word[100], alpha[26];
int main(void)
{
	scanf("%s", word);
	int i = 0;
	while (word[i]) {
		alpha[word[i] - 'a']++;
		i++;
	}
	for (int i = 0; i < 26; i++) printf("%d ", alpha[i]);
	return 0;
}