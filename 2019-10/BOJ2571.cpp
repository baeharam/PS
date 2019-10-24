#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int SIZE = 100;
struct coor{int x,y;};
vector<coor> cc;
vector<int> stack;
bool board[SIZE][SIZE];
int dp[SIZE][SIZE];
int n,w,h,ans;

int main(void)
{
  scanf("%d",&n);
  cc.resize(n);
  for(int i=0; i<n; i++) 
    scanf("%d%d",&cc[i].x,&cc[i].y);

  for(coor c : cc){
    for(int i=c.x; i<c.x+10; i++){
      for(int j=c.y; j<c.y+10; j++){
        board[i][j] = true;
      }
    }
  }

  for(int i=1; i<SIZE; i++){
    for(int j=1; j<SIZE; j++){
      dp[i][j] = board[i][j] ? dp[i-1][j] + 1 : 0;
    }
  }


  for(int i=0; i<SIZE; i++){
    for(int j=0; j<SIZE; j++){
      while(!stack.empty() && dp[i][stack.back()] > dp[i][j]){
        w = dp[i][stack.back()];
        stack.pop_back();
        h = j;
        if(!stack.empty()) h = j - stack.back() - 1;
        ans = max(ans, w*h);
      }
      stack.push_back(j);
    }
    while(!stack.empty()){
      w = dp[i][stack.back()];
      stack.pop_back();
      h = SIZE;
      if(!stack.empty()) h = SIZE - stack.back() - 1;
      ans = max(ans, w*h);
    }
  }
  printf("%d\n",ans);
  return 0;
}