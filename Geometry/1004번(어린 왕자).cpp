#include <cstdio>

int tc, x1, y1, x2, y2, n, p, f;
bool samep, samef, same;

struct c {
	int x;
	int y;
	int r;
};

c coor[50];

inline bool in(int _x1, int _y1, int _x2, int _y2, int r)
{
	return ((_x2 - _x1)*(_x2 - _x1) + (_y2 - _y1)*(_y2 - _y1) < r*r);
}

int main(void)
{
	scanf("%d", &tc); same = true;

	while (tc--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &coor[i].x, &coor[i].y, &coor[i].r);
			samep = in(x1, y1, coor[i].x, coor[i].y, coor[i].r);
			samef = in(x2, y2, coor[i].x, coor[i].y, coor[i].r);
			// 두 점이 다른 원에 있는 경우
			if (samep!=samef) {
				same = false;
				if (samep) p++;
				if (samef) f++;
			}
		}
		same ? puts("0") : printf("%d\n", p + f);
		p = f = 0; same = true;
	}
	return 0;
}