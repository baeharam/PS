#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int SIZE = 100;
int n,k,ans;
int stuff[SIZE+1],plug[SIZE+1];
queue<int> idx[SIZE+1];

int main(void)
{
  scanf("%d%d",&n,&k);
  for(int i=1; i<=k; i++){
    scanf("%d",&stuff[i]);
    idx[stuff[i]].push(i);
  }
  for(int i=1; i<=k; i++){
    bool isPlugged = false;
    for(int j=1; j<=n; j++){
      if(!plug[j] || plug[j] == stuff[i]){
        idx[stuff[i]].pop();
        if(!plug[j]) plug[j] = stuff[i];
        isPlugged = true;
        break;
      }
    }
    if(!isPlugged){
      int far = 0, pos = 0;
      for(int j=1; j<=n; j++){
        if(idx[plug[j]].empty()){
          far = 2e9;
          pos = j;
        }
        else if(far < idx[plug[j]].front()){
          far = idx[plug[j]].front();
          pos = j;
        }
      }
      idx[stuff[i]].pop();
      plug[pos] = stuff[i];
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}