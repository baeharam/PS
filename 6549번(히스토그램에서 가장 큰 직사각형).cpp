#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

// 세그먼트 트리 초기화
void init(std::vector<int> &height, std::vector<int> &tree, int node, int start, int end)
{
	if (start == end) tree[node] = start;
	else {
		int mid = (start + end) / 2;
		init(height, tree, node * 2, start, mid);
		init(height, tree, node * 2 + 1, mid + 1, end);
		if (height[tree[node * 2]] < height[tree[node * 2 + 1]]) tree[node] = tree[node * 2];
		else tree[node] = tree[node * 2 + 1];
	}
}

// 세그먼트 트리에서 주어진 구간의 최솟값을 요구하는 쿼리
int query(std::vector<int> &height, std::vector<int> &tree, int node, int start, int end, int l, int r)
{
	if (l > end || r < start) return -1;
	else if (l <= start && r >= end) return tree[node];
	else {
		int mid = (start + end) / 2;
		int q1 = query(height, tree, node * 2, start, mid, l, r);
		int q2 = query(height, tree, node * 2 + 1, mid + 1, end, l, r);

		if (q1 == -1) return q2;
		else if (q2 == -1) return q1;
		else {
			if (height[q1] <= height[q2]) return q1;
			else return q2;
		}
	}
}

// 분할정복을 통한 직사각형의 최댓값 구하기
long long largest(std::vector<int> &height, std::vector<int> &tree, int start, int end)
{
	int n = height.size();
	int min = query(height, tree, 1, 0, n - 1, start, end); // 주어진 범위의 최솟값 인덱스
	
	// 현재 범위에서 최소높이로 계산된 넓이.
	long long area = static_cast<long long>(end - start + 1)*static_cast<long long>(height[min]);

	// 범위의 시작이 최소높이의 인덱스보다 작으면, 최소높이 인덱스 전까지의 범위에서 넓이 최댓값을 구한다.
	// 그리고 현재 범위의 넓이와 비교해서 업데이트 한다.
	if (start <= min - 1) {
		long long temp = largest(height, tree, start, min - 1);
		if (temp > area) area = temp;
	}
	// 범위의 끝이 최소높이의 인덱스보다 크면, 최소높이 인덱스 이후부터의 범위에서 넓이 최댓값을 구한다.
	// 그리고 현재 범위의 넓이와 비교해서 업데이트 한다.
	if (end >= min + 1) {
		long long temp = largest(height, tree, min + 1, end);
		if (temp > area) area = temp;
	}
	return area;
}

int main(void)
{
	int n, h; scanf("%d", &n);
	while (n) {
		int tree_h = static_cast<int>(std::ceil(log2(n))) + 1;
		int tree_size = static_cast<int>(std::pow(2.0, tree_h));

		std::vector<int> height;
		std::vector<int> tree(tree_size);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &h);
			height.push_back(h);
		}

		init(height, tree, 1, 0, n - 1);
		printf("%lld\n", largest(height, tree, 0, n - 1));
		scanf("%d", &n);
	}

	return 0;
}