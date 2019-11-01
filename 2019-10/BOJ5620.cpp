#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;
vector<pii> px;
int n;

int dist(pii p1, pii p2){
  int xx = p1.first-p2.first;
  int yy = p1.second-p2.second;
  return xx*xx+yy*yy;
}

int findClosest(int l, int r, vector<pii>& py)
{
  if(l == r){
    py.push_back(px[l]);
    return 2e9;
  }
  vector<pii> left, right;
  int d = min(findClosest(l,(l+r)/2,left),findClosest((l+r)/2+1,r,right));
  int li = 0, ri = 0;
  while(li < left.size() && ri < right.size()){
    if(left[li].second > right[ri].second){
      py.push_back(right[ri]);
      ri++;
    } else{
      py.push_back(left[li]);
      li++;
    }
  }
  while(li < left.size()) py.push_back(left[li++]);
  while(ri < right.size()) py.push_back(right[ri++]);
  
  for(int i=0; i<right.size(); i++){
    for(int j=0; j<left.size(); j++){
      if(abs(left[j].second-right[i].second) >= d) break;
      if(abs(left[j].first-right[i].first) >= d) continue;
      d = min(d, dist(left[j],right[i]));
    }
  }
  return d;
}

int main(void)
{
  scanf("%d",&n);
  px.resize(n);
  for(int i=0; i<n; i++) scanf("%d%d",&px[i].first,&px[i].second);
  sort(px.begin(), px.end());
  vector<pii> py;
  printf("%d\n",findClosest(0,n-1,py));
  return 0;
}