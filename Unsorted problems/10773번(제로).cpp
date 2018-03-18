#include <iostream>
#include <stack>

int main(void)
{
	int k,n; std::cin >> k;
	std::stack<int> jangboo;
	while (k--){
		std::cin >> n;
		if (n != 0) jangboo.push(n);
		else jangboo.pop();
	}

	int sum = 0;
	while (jangboo.size()){
		sum += jangboo.top();
		jangboo.pop();
	}

	std::cout << sum;

	return 0;
}