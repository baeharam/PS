#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<int> numv,stack;
vector<char> charv;

int main(void)
{
  cin >> s;
  int i = 0;
  while(i < s.length()){
    int f = 1;
    while(i < s.length() && s[i] >= '0' && s[i] <= '9'){
      i++;
      f *= 10;
    }
    int k = 1, num = 0, idx = i - 1;
    while(k < f){
      num += (s[idx]-'0')*k;
      k *= 10;
      idx--;
    }
    numv.push_back(num);
    if(i >= s.length()) break;
    else{
      charv.push_back(s[i]);
      i++;
    }
  }

  int numi = 1, chari = 0, ans = numv[0];
  while(numi < numv.size() && chari < charv.size()){
    if(charv[chari] == '-'){
      stack.push_back(numv[numi]);
      chari++; numi++;
      while(chari < charv.size() && charv[chari] == '+'){
        stack.push_back(numv[numi]);
        chari++; numi++;
      }
      while(!stack.empty()){
        ans -= stack.back();
        stack.pop_back();
      }
    } else if(charv[chari] == '+'){
      ans += numv[numi];
      chari++; numi++;
    }
  }
  cout << ans << '\n';
  return 0;
}