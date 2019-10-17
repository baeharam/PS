#include <iostream>
#include <algorithm>
using namespace std;

struct xy {
	int x;
	int y;
};

xy coor[100001];

bool operator<(xy c1, xy c2) {
	if (c1.x < c2.x) return true;
	else if (c1.x > c2.x) return false;
	else return c1.y < c2.y;
}

int main(void)
{
	int n; cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> coor[i].x >> coor[i].y;

	sort(coor, coor + n);

	for (int i = 0; i < n; i++)
		cout << coor[i].x << ' ' << coor[i].y << '\n';
	
	return 0;
}