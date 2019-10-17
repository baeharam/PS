#include <iostream>
#include <cstdio>

class Node{
private:
	int data;
	Node* prevNode;
public:
	Node(int data, Node* prevNode);
	int getData() const { return data; }
	void setPrev(Node* prev);
	Node* getPrev() const;
};

Node::Node(int num, Node* prev)
	:data(num), prevNode(prev)
{}

void Node::setPrev(Node* prev)
{
	this->prevNode = prev;
}

Node* Node::getPrev() const
{
	return prevNode;
}

class Stack{
private:
	Node* topNode;
	int size;
public:
	Stack();
	~Stack();
	void Push(const int& data);
	int Pop();
	bool IsEmpty() const;
	int Size() const;
	int Top() const;
	bool find(int data);
	
};

// 생성자
Stack::Stack() :topNode(NULL), size(0)
{}

// 소멸자 topNode~마지막 prevNode까지 delete해주기
Stack::~Stack()
{
	Node* top = this->topNode;
	while (top){
		Node* old = top;
		top = top->getPrev();
		delete old;
	}
}

// Push
void Stack::Push(const int& data)
{
	// 비어있다면 새로운 객체를 할당한다.
	if (this->topNode == NULL)
		this->topNode = new Node(data, NULL);
	// 아니라면 포인터변수에 topNode를 담고
	// topNode에 새로운 객체를 대입한다. temp는 prevNode에 대입된다.
	else{
		Node* temp = topNode;
		this->topNode = new Node(data, temp);
	}
	this->size++;
}

// 가장 위의 값 제거 후 리턴
int Stack::Pop()
{
	// 아무것도 없으면 -1 리턴
	if (this->topNode == NULL) return -1;

	// 임시변수들에 데이터와 topNode를 담는다.
	int temp = this->topNode->getData();
	Node *old = this->topNode;

	// 만약 prevNode가 NULL이라면 topNode만 NULL로 초기화해주면 된다.
	if (this->topNode->getPrev() == NULL)
		this->topNode = NULL;
	// 아니라면 topNode와 prevNode를 한칸씩 내려준다.
	else{
		this->topNode = this->topNode->getPrev();
		this->topNode->setPrev(this->topNode->getPrev());
	}

	// 메모리에 할당되었던 topNode를 해제해주고 길이가 줄어든다.
	// 데이터를 리턴해준다.
	this->size--;
	delete old;
	return temp;
}

// 비어있는지 여부 리턴
bool Stack::IsEmpty() const
{
	if (this->size) return false;
	else return true;
}

// 몇개 있는지 리턴
int Stack::Size() const
{
	return this->size;
}

// 가장 위의 값 제거하지 않고 리턴
int Stack::Top() const
{
	if (!IsEmpty()) return this->topNode->getData();
	else return -1;
}

// 특정 값 찾기
bool Stack::find(int data)
{
	Node* findNode = this->topNode;
	while (findNode){
		if (data == findNode->getData()) return true;
		else findNode = findNode->getPrev();
	}
	return false;
}

int main(void)
{
	Stack s;
	int n, num; scanf("%d", &n);
	int *list = new int[n];
	int before = 0;
	char sign[200000] = { 0 };

	for (int i = 0; i < n; i++) scanf("%d", &list[i]);
	
	for(int i=0,k=0; i<n; i++){
		// 숫자가 스택에 없으면 그 숫자까지 스택에 채운다음 pop
		if (!s.find(list[i])){
			// 추가되었던 최댓값보다 숫자가 작으면 NO
			if (before >= list[i]) { before = -1; break; }
			for (int j = before + 1; j <= list[i]; j++){
				sign[k++] = '+';
				s.Push(j);
			}
			sign[k++] = '-'; s.Pop(); before = list[i];
		}
		// 숫자가 스택에 있으면 나올 때까지 Pop
		else{
			int temp = s.Pop();
			sign[k++] = '-';
			while (temp != list[i]){ temp = s.Pop(); sign[k++] = '-'; }
		}

	}

	if (before == -1) printf("NO\n");
	else{
		for (int i = 0; i < 200000; i++){
			if (sign[i] == 0) break;
			printf("%c\n", sign[i]);
		}
	}

	

	delete[] list;

	return 0;

}
