#include <iostream>
#include <cmath>
#include <cstdio>

typedef long long ll;

ll sum(ll tree[], int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && right >= end) {
		std::cout << start << " 부터 " << end << " 까지의 합\n";
		return tree[node];
	}
	
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}


// 세그먼트 트리의 어떤 노드 값을 변경했을 때 그에 관련된 모든 노드의 값을 갱신하는 함수
void update(ll tree[], int node, int start, int end, int index, ll diff)
{
	std::cout << start << " 부터 " << end << " 까지 ";
	// 부분합 범위에 index가 포함되지 않을 경우 함수를 종료한다.
	if (start > index || end < index) {
		std::cout << "인덱스 범위 벗어남\n";
		return;
	}

	// 포함될 경우 diff(바꾼 숫자와 기존 숫자의 차이)를 더해주어 갱신한다.
	std::cout << tree[node] << "에 " << diff << "만큼 더해져서 ";
	tree[node] += diff;
	std::cout << tree[node] << "가 됨\n";

	// 숫자를 변경한 노드를 만날때까지 지속한다.
	if (start != end) {
		// 이것도 init함수의 원리와 동일하게 자식노드들로 index 범위에 포함되면 갱신하는 형태
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

// 부분합 노드로 세그먼트 트리를 초기화하는 함수
ll init(ll tree[], ll arr[], int node, int start, int end)
{
	// 리프노드일 경우 배열 값이므로 그대로 초기화
	if (start == end) return tree[node] = arr[start];

	// 구간을 나눠야 하는데 그 기준을 mid로 잡는다.
	int mid = (start + end) / 2;

	// 다시 init함수를 호출하여 현재 노드의 자식노드들 즉 node*2와 node*2+1로 부분합을 구하게 한다.
	// 이 호출로 인해 결국 리프노드까지 도달하게 되며 호출이 종료되고 루트노드까지 올라오는 방식이다.
	return tree[node] = init(tree, arr, node * 2, start, mid) + init(tree, arr, node * 2 + 1, mid + 1, end);
}

int main(void)
{
	int n, m, k; std::cin >> n >> m >> k;

	// arr의 인덱스는 0부터 시작
	ll *arr = new ll[n];
	for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

	// 세그먼트 트리 높이와 할당할 배열의 크기 구하기
	int h = static_cast<int>(std::ceil(std::log2(n))) + 1;
	int tree_size = static_cast<int>(std::pow(2.0, h));

	// tree의 인덱스는 1부터 시작 (노드 1번)
	ll *tree = new ll[tree_size];

	// 세그먼트 트리 초기화
	init(tree, arr, 1, 0, n - 1);

	int a, b, c;
	for (int i = 0; i < m + k; i++) {
		scanf("%d %d %d", &a, &b, &c);
		b--;
		// 이 부분에서 diff와 arr[b]를 초기화하는 부분을 바깥에 놔서 계속 틀림
		// 바깥에 놓으면 a=2일때도 실행됨!! 주의!!
		if (a == 1){
			ll diff = (arr[b] - c) * -1; arr[b] = c;
			update(tree, 1, 0, n - 1, b, diff);
		}
		else if (a == 2) printf("%lld\n", sum(tree, 1, 0, n - 1, b, c - 1));
	}


	delete[] arr, tree;

	return 0;
}