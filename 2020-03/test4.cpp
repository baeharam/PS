#include <bits/stdc++.h>
using namespace std;

vector<string> names;
map<string, int> cnt;

string solution(string &S, string &C) {
	for(int i=0; i<(int)C.length(); i++){
		if(isupper(C[i])) C[i] = tolower(C[i]);
	}
	int sidx = 0;
	while(true) {
		int tidx = S.find(";");
		if(tidx == (int)string::npos) break;
		names.push_back(S.substr(sidx, tidx));
		S.erase(sidx, tidx+2);
	}
	names.push_back(S);
	string ans = "";
	for(auto name : names){
		string orgName = "";
		for(char c : name) orgName += c;
		vector<string> subnames;
		sidx = 0;
		while(true) {
			int tidx = name.find(" ");
			if(tidx == (int)string::npos) break;
			subnames.push_back(name.substr(sidx, tidx));
			name.erase(sidx, tidx+1);
		}
		subnames.push_back(name);
		for(auto &subname : subnames){
			for(int i=0; i<(int)subname.length(); i++){
				if(isupper(subname[i])) subname[i] = tolower(subname[i]);
			}
		}
		string lastName = subnames[(int)subnames.size() - 1];
		int hidx = lastName.find("-");
		if(hidx != (int)string::npos) lastName.erase(hidx, 1);

		string email = lastName + "_" + subnames[0];
		if(cnt.find(email) == cnt.end()) cnt[email] = 1;
		else {
			cnt[email]++;
			email += to_string(cnt[email]);
		}
		ans += (orgName + " <" + email + "@" + C + ".com>; ");
	}
	ans = ans.substr(0, (int)ans.length() - 2);
	return ans;
}