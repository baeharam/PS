#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int p[101],r[101],v[101],num[101];
int n,k,a,b;
vector<pair<int,int>> re;

int find(int a)
{
    if(p[a]==a) return a;
    else return p[a] = find(p[a]);
}

void uni(int a, int b)
{
    int p1 = find(a);
    int p2 = find(b);

    if(p1==p2) return;

    if(r[p1]<r[p2]) p[p1]=p2;
    else if(r[p1]>r[p2]) p[p2]=p1;
    else {
        p[p1] = p2;
        r[p2]++;
    }
}

int main(void)
{
    scanf("%d%d",&n,&k);
    for(int i=0; i<k; i++){
        scanf("%d%d",&a,&b);
        re.push_back({a,b});
    }

    for(int i=1; i<=n; i++){
        p[i] = i;
        r[i] = 1;
    }

    for(pair<int,int> p : re) {
        uni(p.first,p.second);
        if(!v[p.first]) v[p.first] = 1;
        if(!v[p.second]) v[p.second] = 1;
    }
    for(int i=1; i<=n; i++) if(v[i]) num[p[i]]++;

    int ans = 0, c = 0;

    for(int i=1; i<=n; i++){
        if(!num[i]) {
            if(!v[i]) c++;
            continue;
        }
        for(int j=i+1; j<=n; j++){
            if(!num[j]) continue;
            ans += num[i]*num[j];
        }
    }

    for(int i=1; i<=n; i++){
        if(!c) break;
        if(!num[i]) continue;
        ans += num[i]*c;
    }

    int ans2 = ((c-1)*(c-1)+(c-1))/2;

    printf("%d",ans+ans2);    

    return 0;
}