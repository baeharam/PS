#include <iostream>

int inorder[100001];
int postorder[100001];

void PreOrder(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe) return;

	int root = postorder[pe]; // postorder의 마지막 값이 root
	std::cout << root << ' '; // root 출력
	int k = 0; // root의 index

	// inorder에서 root값의 index를 찾는 과정
	for (int i = is; i <= ie; i++) {
		if (inorder[i] == root) {
			k = i;
			break;
		}
	}

	/* 어떻게 동작하는지 볼려고 하는 출력형식
	std::cout << "inorder : " << is << "부터 " << ie << "까지\n";
	std::cout << "postorder : " << ps << "부터 " << pe << "까지\n";
	std::cout << "k : " << k << '\n';*/

	// inorder의 시작과 끝을 전달할 때는 k기준으로 왼쪽과 오른쪽으로만 나눠주면 됨
	// 문제는 postorder의 시작과 끝을 어떻게 나누어주는지가 관건!!
	// 문제를 재귀적으로 해결하기 때문에 문제가 분할됬을때도 범위의 적용방식이 같아야 함. 이 부분을 계속 간과해서 결국 못풀었음
	// root를 구하는 기준이 항상 postorder의 마지막 값인 postorder[pe]인 것을 기억해야 한다.

	// postorder의 범위는 시작과 끝이 있고 왼쪽과 오른쪽이 있음
	// 왼쪽의 시작 : 항상 ps인 것은 자명
	// 왼쪽의 끝 : 원래 k-1로 단순히 접근했는데 ps,is를 사용하지 않으면 분할 했을 때 적용 안됨. ps+k-(is+1)
	// 오른쪽의 시작 : 왼쪽의 끝 다음이므로 당연히 ps+k-is
	// 오른쪽의 끝 : postorder[pe]부터 사용하기 때문에 index가 하나씩 줄어든다. 따라서 pe-1

	// 핵심인 ps+k-(is+1)을 파악해야 하는 문제. 하지만 이런 방식을 알아내기가 무척 힘들다.
	// 이 문제에서 깨우쳐 준 것은 하나의 대상에서만 생각하지 말고 다른 대상도 고려해야 한다는 것. 또한 index의 관계를 제대로 파악하고
	// 해야한다는 것이다. 대충하면 절대 못 푼다... 제발 좀 제대로 하자.
	PreOrder(is, k - 1, ps, ps + k - (is + 1));
	PreOrder(k + 1, ie, ps + k - is, pe - 1);
}

int main(void)
{
	int n; std::cin >> n;

	for (int i = 1; i <= n; i++) std::cin >> inorder[i];
	for (int i = 1; i <= n; i++) std::cin >> postorder[i];

	PreOrder(1, n, 1, n);
	return 0;
}