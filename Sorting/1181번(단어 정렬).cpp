#include <cstdio>
#include <algorithm>
#include <cstring>

// sort함수의 기준이 될 함수
// 길이가 같으면 사전 기준으로 앞에 있는 것이 우선되고
// 길이가 다르면 더 짧은게 우선된다.
bool comp(char* a, char* b)
{
	int len_a = strlen(a), len_b = strlen(b);
	int compare = strcmp(a, b);
	if (len_a == len_b)
		return compare < 0;
	return len_a < len_b;
}

int main(void)
{
	int n; scanf("%d", &n);

	// 단어의 개수만큼 이중포인터 배열 동적할당
	char **list = new char*[n];

	// 각자의 포인터에 문자열 최대길이+널문자 51의 char 배열 동적할당
	for (int i = 0; i < n; i++) list[i] = new char[50+1];
	
	// scanf로 50개만 받을 수 있도록 설정
	for (int i = 0; i < n; i++) scanf("%50s", list[i]);

	// sort함수를 통해 길이가 작은순서대로 정렬
	std::sort(list, list + n, comp);

	for (int i = 0; i < n; i++){
		if (!strcmp(list[i], " ")) continue;
		for (int j = i + 1; j < n; j++){
			if (!strcmp(list[i], list[j])) strcpy(list[j], " ");
		}
	}

	

	// 빈 문자열이 아닌경우만 출력
	for (int i = 0; i < n; i++){
		if (strcmp(list[i], " ") != 0)
			printf("%s\n", list[i]);
	}

	// 메모리 해제
	for (int i = 0; i < n; i++) delete[] list[i];
	delete[] list;

	return 0;
}