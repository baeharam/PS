#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool visited[100005];
int time[100005];

int main(void)
{
	int n, k; cin >> n >> k;

	visited[n] = true;

	queue<int> adj;
	adj.push(n);
	time[n] = 0;

	while (!adj.empty()) {
		int v = adj.front(); adj.pop();
		if (v == k) break;
		if (v-1>=0 && !visited[v - 1]) {
			adj.push(v - 1);
			time[v - 1] = time[v] + 1;
			visited[v - 1] = true;
		}
		if (v+1<=100000 && !visited[v + 1]) {
			adj.push(v + 1); 
			time[v + 1] = time[v] + 1;
			visited[v + 1] = true;
		}
		if (v*2<=100000 && !visited[v * 2]) {
			adj.push(v * 2); 
			time[v * 2] = time[v] + 1;
			visited[v * 2] = true;
		}
	}
	cout << time[k];
	return 0;
}