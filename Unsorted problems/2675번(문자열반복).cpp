#include <cstdio>
#include <cstring>

int main(void)
{
	int test_case,r;
	char s[20];
	scanf("%d", &test_case);
	char **list = new char*[test_case];

	for (int i = 0; i < test_case; i++){
		scanf("%d %s", &r, s);
		list[i] = new char[strlen(s)*r + 1];
		char *t = new char[strlen(s)*r + 1];
		for (int j = 0; j < strlen(s)*r; j+=r){
			for (int k = 0; k < r; k++)
				t[j + k] = s[j/r];
		}
		t[strlen(s)*r] = '\0';
		strcpy(list[i], t);
		delete[] t;
	}

	for (int i = 0; i < test_case; i++){
		printf("%s\n", list[i]);
		delete[] list[i];
	}

	delete[] list;

	return 0;
}