#include <iostream>

int lcm(int m, int n)
{
	int a = m, b = n,tmp;
	while (b)
	{
		tmp = a;
		a = b;
		b = tmp%b;
	}

	return (m*n)/a;
}

int main(void)
{
	int tc,m,n,x,y;
	std::cin >> tc;

	for (int i = 0; i < tc; i++){
		std::cin >> m; std::cin >> n; std::cin >> x; std::cin >> y;
		int lcmNum = lcm(m, n);
		while (x != y && x <= lcmNum){
			if (x < y) x += m;
			else y += n;
		}

		if (x != y){ std::cout << "-1" << std::endl; }
		else { std::cout << x << std::endl; }
	}

	return 0;
}