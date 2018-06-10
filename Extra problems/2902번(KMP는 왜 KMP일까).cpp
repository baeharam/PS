#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

char s[101];
vector<char> ans;

int main(void)
{
	scanf("%s", s);
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 65 && s[i] <= 90) ans.push_back(s[i]);
	}
	for (int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
	return 0;
}