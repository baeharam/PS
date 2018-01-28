#include <iostream>
#include <queue>

// 궁금한 문서를 마킹하기 위한 상수
const int ans = 100;

int main(void)
{
	int tc; std::cin >> tc;
	int n, m; // n=문서의개수(<=100) m=위치(0<=n<n)

	int doc,max; // 입력될 문서와 제일 큰 값 

	// 중요도가 들어갈 큐
	std::queue<int> printer;
	// 최댓값을 찾기 위한 큐
	std::priority_queue<int> maxFinder;
	// 최종 배열이 된 큐
	std::queue<int> answer;

	while (tc--){
		std::cin >> n; std::cin >> m;

		// 큐에 중요도 숫자들을 순서대로 집어넣고
		// 제일 큰 값을 체크해둔다.
		for (int i = 0; i < n; i++){
			std::cin >> doc;
			maxFinder.push(doc);
			// m번째 값을 기억하기 위해 마킹상수 100을 더해준다.
			if (i == m) doc += ans;
			printer.push(doc);
		}

		// max값을 maxFinder에서 빼서 넣는다.
		max = maxFinder.top(); maxFinder.pop();

		// 사용할 때마다 함수를 호출하지 않기 위해
		// 임시변수 temp에 담아둔다.
		int temp = printer.front();

		// 앞의 값이 제일 큰지 알려주는 변수
		bool isMax = false;

		// 큐가 비워질 때까지 반복
		while (!printer.empty()){
			// 비교하는 값이 100보다 큰 경우가 있기 때문에 체크
			if (temp > ans)
				max > temp - ans ? isMax = false : isMax = true;
			else
				max > temp ? isMax = false : isMax = true;

			// 맨 앞이 최댓값이 아니라면 빼서 뒤로 보내고
			// temp 업데이트
			if (!isMax && !printer.empty()){
				printer.pop();
				printer.push(temp);
				temp = printer.front();
			}
			// 맨 앞이 최댓값이라면 max 업데이트
			// maxFinder를 사용(우선순위 큐)
			// printer의 제일 앞에 값을 answer에 집어넣는다.
			else if (isMax){
				if (!maxFinder.empty())
				{max = maxFinder.top(); maxFinder.pop();}
				answer.push(printer.front()); printer.pop();
				if(!printer.empty()) temp = printer.front();
			}
			
		}

		// answer의 크기가 계속 변하기 때문에 고정
		int size = answer.size();
		for (int i = 0; i<size; i++){
			if (answer.front() > ans) std::cout << i + 1 << '\n';
			answer.pop();
		}
	}

	return 0;
}