#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,a[1000000];
vector<int> lis;

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    lis.push_back(a[0]);
    for(int i=1; i<n; i++) {
        if(lis[lis.size()-1]<a[i]) lis.push_back(a[i]);
        else {
            vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), a[i]);
            *it = a[i];
        }
    }

    printf("%d",lis.size());
    return 0;
}