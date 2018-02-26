#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

const int min = -1000000000;
const int max = 1000000000;

// 합병정렬 알고리즘을 이용해서 세그먼트 트리의 부분벡터 정렬
std::vector<int> Merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> temp;
	int i = 0, j = 0, a_size = a.size(), b_size = b.size();

	while (i < a_size && j < b_size) {
		if (a[i] < b[j]) {
			temp.push_back(a[i]);
			i++;
		}
		else {
			temp.push_back(b[j]);
			j++;
		}
	}

	if (i == a_size) {
		while (j < b_size) {
			temp.push_back(b[j]);
			j++;
		}
	}
	else if (j == b_size) {
		while (i < a_size) {
			temp.push_back(a[i]);
			i++;
		}
	}

	return temp;
}

// 주어지는 i,j,k(쿼리)마다 i~j에 속한 구간벡터들의 포인터를 하나의 벡터로 모은다.
void query(std::vector<std::vector<int>*> &total, std::vector<int> tree[], int node, int start, int end, int left, int right)
{
	// 범위를 벗어나는 경우
	if (left > end || right < start) return;
	// 범위 안에 start~end가 속한 경우, 그 벡터자체의 주소를 저장
	if (left <= start && right >= end) total.push_back(&tree[node]);

	// start~end 안에 범위가 속한 경우 왼쪽/오른쪽 자식 노드들로 재귀호출
	else {
		int mid = (start + end) / 2;
		query(total, tree, node * 2, start, mid, left, right);
		query(total, tree, node * 2 + 1, mid + 1, end, left, right);
	}
}

// k번째 숫자를 찾는 함수
int kthElement(std::vector<int> tree[], int n, int left, int right, int k)
{
	// 정렬된 구간벡터들의 포인터를 가지는 벡터, 레퍼런스로 전달한다.
	std::vector<std::vector<int>*> total;
	// i=left, j=right로 주어진 구간의 쿼리함수 호출
	query(total, tree, 1, 0, n - 1, left, right);

	// num은 임의의 숫자보다 작은 구간벡터들의 숫자 개수
	// l1, r1은 -10억, 10억부터 시작해서 Binary Search진행
	// mid1 = Binary Search에 사용되며 임의의 숫자를 의미한다.
	int num = 0, l1 = min, r1 = max, mid1;

	// k번째 숫자를 찾는 Binary Search
	while (l1<=r1) {
		num = 0;
		// 벡터포인터들을 갖는 벡터의 크기만큼 반복
		for (int i = 0; i < total.size(); i++) {
			mid1 = (l1 + r1) / 2; 
			// l2,r2는 0과 포인터가 가리키는 벡터의 크기-1(인덱스)
			// mid2 = 일반적인 Binary Search의 중간값을 의미
			int l2 = 0, r2 = total[i]->size() - 1, mid2;
			// 임의의 숫자 mid1보다 작은 숫자의 개수를 찾는 Binary Search
			while(l2<=r2) {
				mid2 = (l2 + r2) / 2;
				// mid1보다 작거나 같으면 이전의 값들은 모두 mid1보다 작은 것이므로 mid2+1부터 다시 조사
				if (mid1 >= total[i]->at(mid2)) l2 = mid2 + 1;
				// mid1보다 크면 이후의 값들은 모두 mid1보다 큰 것이므로 mid2-1까지 다시 조사
				else r2 = mid2 - 1;
			}
			// r2가 의미하는 것은 r2 이전의 값들이 모두 r2보다 작으므로 r2(인덱스)+1이 그 개수.
			num += (r2 + 1);
		}
		// 임의의 숫자보다 작은 숫자의 개수가 k보다 작을 경우 임의의 숫자는 더 커져야 하고
		// 크거나 같을 경우 임의의 숫자는 더 작아져야 한다.
		num < k ? l1 = mid1 + 1 : r1 = mid1 - 1;
	}
	return l1;
}

// 세그먼트 트리 초기화
std::vector<int> init(int arr[], std::vector<int> tree[], int node, int start, int end)
{
	// 리프노드까지 도달했을 때 그 값을 push_back하고 리턴
	if (start == end) {
		tree[node].push_back(arr[start]);
		return tree[node];
	}

	// 리프노드가 아닌 경우 왼쪽/오른쪽 자식노드의 벡터들을 합병해서 현재노드에 업데이트
	int mid1 = (start + end) / 2;
	return tree[node] = Merge(init(arr, tree, node * 2, start, mid1), init(arr, tree, node * 2 + 1, mid1 + 1, end));
}

int main(void)
{
	int n, m; std::cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	// 세그먼트 트리의 높이와 세그먼트 트리로 쓰일 배열의 크기 구하기
	int h = static_cast<int>(std::ceil(std::log2(n)) + 1);
	int tree_size = static_cast<int>(std::pow(2.0, h) - 1);

	// 세그먼트 트리 생성
	std::vector<int> *tree = new std::vector<int>[tree_size + 1];

	// 초기화
	init(arr, tree, 1, 0, n - 1);


	int i, j, k;
	while (m--) {
		// 쿼리 입력
		scanf("%d %d %d", &i, &j, &k);
		// 주어지는 i,j가 index기준이 아니므로 1씩 빼준다.
		i--; j--;
		printf("%d\n", kthElement(tree, n, i, j, k));
	}

	// 메모리 해제
	delete[] arr, tree;
	return 0;
}