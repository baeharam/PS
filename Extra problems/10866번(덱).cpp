#include <iostream>
#include <string>

// 큐에 들어가질 노드 클래스
class Node {
private:
	int data;
	// 이전 노드와 다음 노드를 가리키는 포인터를 갖는다.
	Node* prevNode;
	Node* nextNode;
public:
	Node(int _data = 0, Node* _prevNode = NULL, Node* _nextNode = NULL);
	Node* getPrev() const;
	Node* getNext() const;
	int getData() const;
	void setPrev(Node* prev);
	void setNext(Node* next);
};

Node::Node(int _data, Node* _prevNode, Node* _nextNode)
	:data(_data), prevNode(_prevNode), nextNode(_nextNode)
{}

Node* Node::getPrev() const
{
	return prevNode;
}

int Node::getData() const
{
	return data;
}

void Node::setPrev(Node* prev)
{
	prevNode = prev;
}

void Node::setNext(Node* next)
{
	nextNode = next;
}

Node* Node::getNext() const
{
	return nextNode;
}

class Deque {
private:
	// 맨 앞과 맨 뒤를 가리키는 포인터를 갖는다.
	Node * frontNode;
	Node* backNode;
	int sizeq;
public:
	Deque() :frontNode(NULL), backNode(NULL), sizeq(0) {}
	~Deque();
	void push_front(int data);
	void push_back(int data);
	int pop_front();
	int pop_back();
	int size();
	int empty();
	void front() const;
	void back() const;
};

// frontNode 부터 쭉 내려오면서 메모리 해제
Deque::~Deque()
{
	Node* front = frontNode;
	while (front) {
		Node* temp = front;
		front = front->getPrev();
		delete temp;
	}
}

// 덱 가장 앞에 데이터를 넣는다.
void Deque::push_front(int data)
{
	Node* newNode = new Node(data, NULL, NULL);
	// 아무것도 없다면 새로 생성해서 frontNode와 backNode를 초기화
	if (!sizeq)
		frontNode = backNode = newNode;
	// 하나라도 있다면 새로 생성해서 frontNode 초기화
	else {
		newNode->setPrev(frontNode);
		frontNode->setNext(newNode);
		frontNode = newNode;
	}
	sizeq++;
}

// 덱 가장 뒤에 데이터를 넣는다.
void Deque::push_back(int data)
{
	Node* newNode = new Node(data, NULL, NULL);
	// 아무것도 없다면 새로 생성해서 frontNode와 backNode를 초기화
	if (!sizeq)
		frontNode = backNode = newNode;
	// 하나라도 있다면 새로 생성해서 backNode 초기화
	else {
		backNode->setPrev(newNode);
		newNode->setNext(backNode);
		backNode = newNode;
	}
	sizeq++;
}

// 덱 가장 앞의 데이터를 빼고 출력한다. (리턴까지)
int Deque::pop_front()
{
	// 큐에 들어있는 정수가 없는 경우
	if (!sizeq) {
		std::cout << -1 << '\n';
		return -1;
	}
	// 큐에 정수가 있는 경우 출력하고 메모리 삭제한 뒤 리턴
	else {
		int num = frontNode->getData();
		std::cout << num << std::endl;
		Node* temp = frontNode;
		frontNode = frontNode->getPrev();
		if (frontNode != NULL) frontNode->setNext(NULL);
		else backNode = NULL;
		delete temp;
		sizeq--;
		return num;
	}
}

// 덱 가장 뒤의 데이터를 빼고 출력한다. (리턴까지)
int Deque::pop_back()
{
	// 큐에 들어있는 정수가 없는 경우
	if (!sizeq) {
		std::cout << -1 << '\n';
		return -1;
	}
	// 큐에 정수가 있는 경우 출력하고 메모리 삭제한 뒤 리턴
	else {
		int num = backNode->getData();
		std::cout << num << std::endl;
		Node* temp = backNode;
		backNode = backNode->getNext();
		if (backNode != NULL) backNode->setPrev(NULL);
		else frontNode = NULL;
		delete temp;
		sizeq--;
		return num;
	}
}

int Deque::size()
{
	std::cout << sizeq << '\n';
	return sizeq;
}

int Deque::empty()
{
	if (sizeq == 0) {
		std::cout << 1 << '\n';
		return 1;
	}
	else {
		std::cout << 0 << '\n';
		return 0;
	}
}

void Deque::front() const
{
	if (!sizeq) std::cout << -1 << '\n';
	else std::cout << frontNode->getData() << '\n';
}

void Deque::back() const
{
	if (!sizeq) std::cout << -1 << '\n';
	else std::cout << backNode->getData() << '\n';
}


int main(void)
{
	std::ios_base::sync_with_stdio(false);
	int n; std::cin >> n; // 1<=n<=10,000
	int data; std::string str; // 1<=data<=100,000
	Deque q;

	while (n--) {
		std::cin >> str;
		if (!str.compare("push_front")) {
			std::cin >> data;
			q.push_front(data);
		}
		else if (!str.compare("push_back")) {
			std::cin >> data;
			q.push_back(data);
		}
		else if (!str.compare("pop_front"))
			q.pop_front();
		else if (!str.compare("pop_back"))
			q.pop_back();
		else if (!str.compare("size"))
			q.size();
		else if (!str.compare("empty"))
			q.empty();
		else if (!str.compare("front"))
			q.front();
		else if (!str.compare("back"))
			q.back();
	}

	return 0;

}