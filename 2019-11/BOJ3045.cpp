#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct Node {
  Node* prev;
  Node* next;
  int num;
  Node(int _num) : prev(NULL),next(NULL),num(_num){}
  void A(Node* pos){
    if(prev != NULL) prev->next = next;
    if(next != NULL) next->prev = prev;
    if(pos->prev != NULL) pos->prev->next = this;
    prev = pos->prev;
    next = pos;
    pos->prev = this;
  }
  void B(Node* pos){
    if(prev != NULL) prev->next = next;
    if(next != NULL) next->prev = prev;
    if(pos->next != NULL) pos->next->prev = this;
    prev = pos;
    next = pos->next;
    pos->next = this;
  }
};

const int MAX_SIZE = 500005;
Node* arr[MAX_SIZE];
int n,m,a,b;
int dp[MAX_SIZE];
char op;
vector<int> v, lis, rlis;

void makeLinkedList()
{
  Node* newNode = new Node(1);
  arr[1] = newNode;
  Node* pointer = newNode;
  for(int i=2; i<=n; i++){
    Node* nextNode = new Node(i);
    arr[i] = nextNode;
    pointer->next = nextNode;
    nextNode->prev = pointer;
    pointer = nextNode;
  }
}

void initVector(int idx) {
  Node* pointer = arr[idx];
  while(pointer != NULL){
    v.push_back(pointer -> num);
    pointer = pointer->next;
  } 
}

int main(void)
{
  scanf("%d%d",&n,&m);
  makeLinkedList();
  while(m--){
    scanf(" %c%d%d",&op,&a,&b);
    if(op == 'A') arr[a]->A(arr[b]);
    else arr[a]->B(arr[b]);
  }
  int bidx;
  for(int i=1; i<=n; i++) {
    if(arr[i]->prev == NULL){
      bidx = i;
      break;
    }
  }
  initVector(bidx);

  for(int i=0; i<v.size(); i++) dp[i] = 1;

  int maxIdx = 0, maxVal = 1;
  lis.push_back(v[0]);
  for(int i=1; i<v.size(); i++){
    auto it = lower_bound(lis.begin(),lis.end(),v[i]);
    if(it == lis.end()){
      lis.push_back(v[i]);
      dp[i] = lis.size();
    } else{
      *it = v[i];
      dp[i] = it - lis.begin() + 1;
    }
    if(maxVal <= dp[i]){
      maxIdx = i;
      maxVal = dp[i];
    }
  }

  lis.clear();
  for(int i=maxIdx; i>=0; i--){
    if(dp[i] != maxVal) continue;
    lis.push_back(v[i]);
    maxVal--;
    if(!maxVal) break;
  }
  for(int i=lis.size()-1; i>=0; i--) rlis.push_back(lis[i]);

  printf("%lu\n",v.size() - rlis.size());
  int cur = 1, lisIdx = 0;
  while(lisIdx < rlis.size()){
    if(cur == rlis[lisIdx]) lisIdx++;
    else printf("A %d %d\n", cur, rlis[lisIdx]);
    cur++;
  }
  int front = rlis[lisIdx - 1];
  while(cur <= n){
    printf("B %d %d\n", cur, front);
    front = cur;
    cur++;
  }
  return 0;
}