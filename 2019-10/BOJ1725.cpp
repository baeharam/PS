#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100000;
stack<int> s;
int height[MAX_SIZE];
int n,ans,w,h;

int main(void)
{
  scanf("%d",&n);
  for(int i=0; i<n; i++) scanf("%d", &height[i]);
  for(int i=0; i<n; i++){
    while(!s.empty() && height[s.top()] > height[i]){
      h = height[s.top()];
      s.pop();
      w = i;
      if(!s.empty()) w = i - s.top() - 1;
      ans = max(ans, w*h);
    }
    s.push(i);
  }
  while(!s.empty()){
    h = height[s.top()];
    s.pop();
    w = n;
    if(!s.empty()) w = n - s.top() - 1;
    ans = max(ans, w*h);
  }
  printf("%d\n",ans);
  return 0;
}