#include <iostream>
#include <queue>

int main(void)
{
	int n, m; std::cin >> n; std::cin >> m;

	std::queue<int> josepus;
	std::queue<int> answer;
	// 1부터 n까지 큐에 넣는다.
	for (int i = 1; i <= n; i++) josepus.push(i);

	// 몇 번째 사람을 제거할지 지정
	int idx = 1;

	// 큐에서 앞의 값을 저장할 임시변수
	int temp = 0;

	// 큐가 비워질 때까지 반복
	while (!josepus.empty()){
		// m번째 사람이 아니라면 큐에서 뺀 다음 뒤에 집어넣기
		if (idx != m){
			temp = josepus.front();
			josepus.pop();
			josepus.push(temp);
			idx++;
		}
		// m번째 사람이라면 빼서 answer 큐에 집어넣기
		else{
			answer.push(josepus.front());
			josepus.pop();
			idx = 1;
		}
	}
	
	// 사이즈 고정
	int size = answer.size();

	for (int i = 0; i < size; i++){
		if (i == 0) {
			if (size == 1) std::cout << '<' << answer.front() << '>';
			else std::cout << '<' << answer.front() << ", ";
		}
		else if (i == size - 1) std::cout << answer.front() << '>';
		else std::cout << answer.front() << ", ";
		answer.pop();
	}

	return 0;
}