#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;
int a[maxn], b[maxn];
int main(){
    int nc, np,p =0,q = 0;
    int sum = 0;
    scanf("%d", &nc);
    for(int i=0; i<nc; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &np);
    for(int i=0; i<np; i++){
        scanf("%d", &b[i]);
    }
    sort(a, a+nc);
    sort(b, b+np);
    while(q<nc && p<np && a[q] <0 && b[p]<0){
        sum+=a[q]*b[p];
        q++, p++;
    }
    q = nc-1, p  = np-1;
    while(q>=0 && p>=0 && a[q] >0 && b[p]>0){
        sum+=a[q]*b[p];
        q--, p--;
    }
    printf("%d", sum);
}
