#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int n;
vector<string> open,close;
map<string,bool> visited;

int main(void)
{
  cin >> n;
  open.resize(n);
  close.resize(n);

  for(int i=0; i<n; i++){
    cin >> open[i];
    visited[open[i]] = false;
  }
  for(int i=0; i<n; i++) cin >> close[i];

  int oi = 0, ci = 0, ans = 0;
  while(oi < n && ci < n){
    if(open[oi].compare(close[ci])){
      if(visited[open[oi]]){
        oi++;
        continue;
      }
      visited[close[ci]] = true;
      ci++;
      ans++;
    }
    else{
      oi++;
      ci++;
    }
  }
  cout << ans << '\n';
  return 0;
}