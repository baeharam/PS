#include <iostream>
#include <stack>

int h[100000];

int main(void)
{
	int n; std::cin >> n;
	while (n) {
		std::stack<int> s;
		for (int i = 0; i < n; i++) std::cin >> h[i];
		long long area = 0;

		for (int i = 0; i < n; i++) {
			// 스택이 비어있지 않고 i번째 직사각형의 높이보다 스택에 들어있는 인덱스의 높이가 큰 경우
			while (!s.empty() && h[s.top()] > h[i]) {
				// 스택에서 pop시키기 전에 높이 저장
				long long height = h[s.top()];
				s.pop();
				// pop했을 때 스택이 비게 되면 그 너비는 i번째 직사각형을 제외한 스택에 들어있던 직사각형의 개수가 너비가 된다.
				long long width = i;
				// pop했을 때 스택에 아직도 있다면 i~s.top()의 길이가 너비가 된다.
				if (!s.empty()) width = i - s.top() - 1;
				// 더 큰 넓이가 오면 갱신
				if (width*height > area) area = width * height;
			}
			// 항상 스택에 인덱스를 넣는다.
			s.push(i);
		}


		// 스택이 비어있지 않은 경우, 오른쪽 끝까지 왔을 때!
		while (!s.empty()) {
			long long height = h[s.top()];
			s.pop();
			long long width = n;
			if (!s.empty()) width = n - s.top() - 1;
			if (width*height > area) area = width * height;
		}
		std::cout << area << '\n';
		std::cin >> n;
	}
	return 0;
}