#include <bits/stdc++.h>
using namespace std;


int main(){
    long long s1  =0, s2 = 0;
    int m;
    scanf("%d", &m);
    int v[100001];
    for(int i=0; i<m; i++){
        scanf("%d", &v[i]);
    }
    sort(v, v+m);
    printf("%d", m%2==0? 0:1);

    for(int l = 0, r = m-1; l<r;l++, r--){
        s1 +=v[l];
        s2 +=v[r];
    }
    if(m%2==0){
        printf(" %lld", abs(s1-s2));
    }else{
        printf(" %lld", abs(s1-s2)+v[m/2]);
    }
}
