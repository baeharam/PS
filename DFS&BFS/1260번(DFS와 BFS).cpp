#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

// 정점의 최대개수
const int max_vertex = 1000+1;
// 벡터를 배열로 만들어서 각 배열은 벡터를 갖게 된다.
// 배열의 index의 최댓값은 1000이므로 max_vertex는 1000+1이 된다.
std::vector<int> graph[max_vertex];

// DFS(깊이 우선 탐색)
// 정점의 개수 그리고 시작번호를 넘겨준다
void DFS(int m, int v)
{
	// 방문여부를 확인하는 bool형 배열을 동적할당하는데
	// 각 정점의 값을 index로 쓰기 때문에 m+1을 해주어야 한다.
	// index는 0부터 시작이므로
	bool *visited = new bool[m + 1];
	for (int i = 1; i <= m; i++) visited[i] = false; // false로 초기화

	// 현재위치, 처음엔 시작번호로 초기화
	int vertex = v;

	// 지나온 경로를 담는 스택을 만든다
	std::stack<int> path;
	// 시작위치를 스택에 넣는다.
	path.push(vertex);

	// 가장 작은 값 (연결된 것이 여러개일때 가장 작은값 찾아야 함)
	int next = 0;

	// vertex에서 방문할 수 있는 곳이 있는지 알려주는 변수
	bool nothing = true;

	// 스택이 완전히 비어지게 될 경우까지 반복한다.
	while (!path.empty()){

		// vertex에 처음 연결되어있는 값
		// 오름차순 정렬되어있으므로 이 값은 방문하지 않은 것이기만 하면 된다.
		// 발견즉시 break해준다. 하지 않으면 계속 바뀌므로
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++)
			if (visited[graph[vertex][i]] == false) {
				next = graph[vertex][i]; break;
			}
		
		// 위에서 필터링된 것은 방문되지 않은 값들이기 때문에
		// 가장 작은값을 구해야 한다.
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++)
			// vertex에 연결된 값들 중 하나라도 방문하지 않은 것이 있다면 nothing을 false로 해주고 나온다.
			if (visited[graph[vertex][i]] == false) { nothing = false; break; }

		// vertex가 방문하지 않은 거라면 출력을 하고 그 값을 방문했다고 표시한다.
		if (visited[vertex] == false){
			std::cout << vertex << " ";
			visited[vertex] = true;
		}
		// nothing이 true이므로 갈곳이 없기 때문에 스택에서 빼내어서 이전 vertex로 돌아간다
		if (nothing){	
			vertex = path.top();
			path.pop();
		}
		// nothing이 false이므로 갈곳이 있기 때문에 업데이트 해야한다.
		// 그리고 vertex를 스택에 넣고 next로 업데이트.
		else{
			path.push(vertex);
			vertex = next;
		}

		//nothing에 false가 들어갈 때가 있으므로 반드시 초기화 해주어야 한다.
		nothing = true;

	}

	delete[] visited; // 메모리해제
}

// BFS(너비 우선 탐색)
// 정점의 개수 그리고 시작번호를 넘겨준다
void BFS(int m, int v)
{
	// 방문여부를 확인하는 bool형 배열을 동적할당하는데
	// 각 정점의 값을 index로 쓰기 때문에 m+1을 해주어야 한다.
	// index는 0부터 시작이므로
	bool *visited = new bool[m + 1];
	for (int i = 1; i <= m; i++) visited[i] = false; // false로 초기화

	// 현재위치, 처음엔 시작번호로 초기화
	int vertex = v;

	// 지나온 경로를 담는 큐를 만든다
	std::queue<int> path;
	// 시작위치를 큐에 넣는다.
	path.push(vertex);
	// 시작위치를 방문했으니 true로 만든다.
	visited[vertex] = true;

	// 큐가 비워질 때까지 반복한다.
	while (!path.empty()){
		// 큐의 제일 앞의 값을 출력하고 뺀다.
		vertex = path.front();
		std::cout << path.front() << " "; path.pop();

		// vertex에 연결되고 방문하지 않았던 vertex를 큐에 넣는다.
		for (std::vector<int>::size_type i = 0; i < graph[vertex].size(); i++){
			if (visited[graph[vertex][i]] == false){
				path.push(graph[vertex][i]);
				visited[graph[vertex][i]] = true;
			}
		}
	}

	delete[] visited; // 메모리해제
}

int main(void)
{
	// 정점 m, 간선 n, 시작번호 v
	int m, n, v;
	std::cin >> m; std::cin >> n; std::cin >> v;

	// 입력하는 2개의 정점
	int v1, v2; 

	while (n--){
		std::cin >> v1; std::cin >> v2;
		// 무방향 그래프이기 때문에 서로 연결시켜준다.
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	// 오름차순 정렬
	for (int i = 0; i < m; i++){
		for (std::vector<int>::size_type j = 0; j < graph[i].size(); j++)
			std::sort(graph[i].begin(), graph[i].end());
	}

	DFS(m, v);
	std::cout << '\n';
	BFS(m, v);

	return 0;
}
