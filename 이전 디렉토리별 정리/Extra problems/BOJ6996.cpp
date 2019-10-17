#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s1,s2;
int tc;
bool check[100];

int main(void)
{
    cin >> tc;
    while(tc--) {
        cin >> s1 >> s2;
        int match = 0;
        int s1_len = s1.length(), s2_len = s2.length();
        if(s1_len!=s2_len) {
            cout << s1 << " & " << s2 << " are NOT anagrams.\n"; 
            continue;
        }
        for(int i=0; i<s1_len; i++){ 
            for(int j=0; j<s2_len; j++) {
                if(toupper(s1[i])==toupper(s2[j]) && !check[j]){
                    check[j] = true;
                    match++;
                    break;
                }
            }
        }
        cout << s1 << " & " << s2 << " are ";
	    int max_len = s1_len > s2_len ? s1_len : s2_len;
        if(match==max_len) cout << "anagrams.";
        else cout << "NOT anagrams.";
        cout << "\n";
        for(int i=0; i<max_len; i++) check[i] = false;
    }
    return 0;
}
