#include <iostream>

int main(void)
{
	char s[15+1];
	std::cin >> s;
	int time = 0;

	int dial[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 
		7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	for (int i = 0; s[i]; i++)
		time += dial[s[i] - 'A'];

	std::cout << time;
	return 0;
}