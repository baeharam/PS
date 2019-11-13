#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 2e9;
int h1,w1,h2,w2;
int dp[51][51][51][51];
int dpr[51][51];

int r(int w, int h)
{
	if(w == h) return 1;
	if(w == 1) return h;
	if(h == 1) return w;

	int &ret = dpr[w][h];
	if(ret != -1) return ret;
	ret = INF;

	for(int i=1; i<w; i++)
		ret = min(ret, r(i, h) + r(w - i, h));

	for(int i=1; i<h; i++)
		ret = min(ret, r(w, i) + r(w, h - i));

	return ret;
}

int f(int h1, int w1, int h2, int w2)
{
	int &ret = dp[h1][w1][h2][w2];
	if(ret != -1) return ret;
	ret = INF;

	int w = w1 - w2;
	int h = h1 - h2;

	for(int i=1; i<h1; i++){
		if(i < h2) ret = min(ret, r(w, i) + f(h1 - i, w1, h2 - i, w2));
		else if(i == h2) ret = min(ret, r(w, i) + r(w1, h1 - i));
		else ret = min(ret, f(i, w1, h2, w2) + r(w1, h1 - i));
	}

	for(int i=1; i<w1; i++){
		if(i < w) ret = min(ret, r(i, h1) + f(h1, w1 - i, h2, w2));
		else if(i == w) ret = min(ret, r(i, h1) + r(w1 - i, h));
		else ret = min(ret, f(h1, i, h2, i - w) + r(w1 - i, h));
	}
	return ret;
}

int main(void)
{
	scanf("%d%d%d%d",&h1,&w1,&h2,&w2);
	memset(dp, -1, sizeof(dp));
	memset(dpr, -1, sizeof(dpr));
	printf("%d\n", f(h1, w1, h2, w2));
	return 0;
}