#include <cstdio>

int n,arr[500000],aux[500000];
long long swap = 0LL;

void merge(int l, int r, int m)
{
    int l_p = l, r_p = m+1, k = 0;

    while(l_p<=m && r_p<=r) {
        while(l_p<=m && arr[l_p]<arr[r_p]) {
            aux[k++] = arr[l_p];
            l_p++;
        }
        while(r_p<=r && arr[r_p]<arr[l_p]) {
            if(l_p<=m) swap+=(m-l_p+1);
            aux[k++] = arr[r_p];
            r_p++;
        }
    }

    for(int i=l_p; i<=m; i++) aux[k++] = arr[i];
    for(int i=r_p; i<=r; i++) aux[k++] = arr[i];

    for(int i=l, k=0; i<=r; i++,k++) arr[i] = aux[k];
}

void mergeSort(int l, int r)
{
    if(l<r) {
        int m = (l+r)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l,r,m);
    }
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&arr[i]);
    mergeSort(0,n-1);
    printf("%lld", swap);
    return 0;
}