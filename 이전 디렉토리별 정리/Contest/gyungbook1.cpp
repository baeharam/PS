#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> st[21], mt[21];
int h,m,t1,t2,tt1,tt2;

int main(void)
{
    scanf("%d:%d",&h,&m);
    scanf("%d%d",&t1,&t2);
    scanf("%d%d",&tt1,&tt2);

    for(int i=0; i<tt1; i++){
        int _h,_m;
        scanf("%d:%d",&_h,&_m);
        st[_h].push_back(_m);
    }

    for(int i=0; i<tt2; i++){
        int _h,_m;
        scanf("%d:%d",&_h,&_m);
        mt[_h].push_back(_m);
    }
    
    auto it = lower_bound(st[h].begin(),st[h].end(),m);
    int minute = 0;
    if(it==st[h].end()){
        for(int i=h+1; i<=20; i++){
            if(st[i].size()==0) continue;
            else {
                minute = st[i][0];
                h = i;
                break;
            }
        }
    } else{
        minute = *it;
    }


    int ch = h, cm = minute;
    int hour = (cm+t1)/60;
    cm = (cm+t1)%60;
    ch += hour;

    it = lower_bound(mt[ch].begin(),mt[ch].end(),cm);
    minute = 0;
    if(it==mt[ch].end()){
        for(int i=ch+1; i<=20; i++){
            if(mt[i].size()==0) continue;
            else {
                minute = mt[i][0];
                ch = i;
                break;
            }
        }
    } else{
        minute = *it;
    }


    hour = (minute+t2)/60;
    cm = (minute+t2)%60;
    ch += hour;

    if(ch<10) printf("0"); printf("%d:",ch);
    if(cm<10) printf("0"); printf("%d",cm);
    return 0;
}