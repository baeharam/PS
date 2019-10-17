#include <iostream>
#include <vector>
#include <string>

std::vector<int> video[64];

int checkSameNumber(int size, int r, int c)
{
	int first = video[r][c];
	if (size == 1) return first;
	for (int i = r; i < r+size; i++) {
		for (int j = c; j < c+size; j++) {
			if (first != video[i][j]) return -1;
		}
	}
	return first;
}

void zipVideo(std::vector<int>& tree, int node, int size, int r, int c)
{
	int isSame = checkSameNumber(size, r, c);
	if (isSame != -1) {
		tree[node] = isSame;
		std::cout << tree[node];
	}
	else {
		std::cout << '(';
		zipVideo(tree, node * 2, size / 2, r, c);
		zipVideo(tree, node * 2 + 1, size / 2, r, c+size / 2);
		zipVideo(tree, node * 2 + 2, size / 2, r+size / 2, c);
		zipVideo(tree, node * 2 + 3, size / 2, r+size / 2, c+size / 2);
		std::cout << ')';
	}
}

int main(void)
{
	int n; std::cin >> n;
	std::string temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		for (int j = 0; j < temp.size(); j++) video[i].push_back(temp[j] - '0');
	}

	std::vector<int> tree(n+4*n+1);
	zipVideo(tree, 1, n, 0, 0);

	//for (int i = 1; i < tree.size(); i++) std::cout << tree[i] << ' ';
	return 0;
}