#include <cstdio>
using namespace std;

int main()
{

	int k = 0; scanf("%d", &k);
	for (int i = 0; i < k; i++) printf("1");
	for (int i = 0; i < k - 1; i++) printf("0");
	return 0;

}