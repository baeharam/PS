#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
int n;
vector<pii> v;

int subtract(int small, int big){
  if(small > big) return 0;
  int h = (big/100) - (small/100);
  int m = (big%100) - (small%100);
  if(m < 0){
    h--;
    m += 60;
  }
  return h*100 + m;
}
int plus10(int target){
  int h = target/100;
  int m = target%100 + 10;
  if(m >= 60) {
    h++;
    m = 0;
  }
  return h*100 + m;
}

int main(void)
{
  scanf("%d", &n);
  v.resize(n);
  for(int i=0; i<n; i++)
    scanf("%d%d",&v[i].first,&v[i].second);
  sort(v.begin(), v.end());
  int start = 0, end = 990, ans = 0;
  bool isNew = true;
  for(pii p : v){
    start = subtract(10,p.first);
    if(isNew){
      end = plus10(end);
      isNew = false;
    }
    ans = max(ans, subtract(end, start));
    if(end < p.second){
      end = p.second;
      isNew = true;
    }
  }
  ans = max(ans, subtract(plus10(end), 2200));
  printf("%d\n",(ans/100*60)+ans%100);
  return 0;
}