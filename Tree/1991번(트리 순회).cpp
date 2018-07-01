#include <cstdio>
#include <vector>
using namespace std;

vector<int> tree[26];

char root, l, r;
int n;

void pre(char s)
{
	if (s == '.') return;
	printf("%c", s);
	pre(tree[s - 'A'][0]);
	pre(tree[s - 'A'][1]);
}

void in(char s)
{
	if (s == '.') return;
	in(tree[s - 'A'][0]);
	printf("%c", s);
	in(tree[s - 'A'][1]);
}

void post(char s)
{
	if (s == '.') return;
	post(tree[s - 'A'][0]);
	post(tree[s - 'A'][1]);
	printf("%c", s);
}


int main(void)
{
	scanf("%d", &n);
	
	while (n--) {
		scanf(" %c %c %c", &root, &l, &r);
		tree[root - 'A'].push_back(l);
		tree[root - 'A'].push_back(r);
	}
	pre('A'); printf("\n");
	in('A'); printf("\n");
	post('A');
	return 0;
}