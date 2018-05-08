#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;
int main(){
    int n;
    int v[maxn], mark[maxn] = {0};
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
        mark[v[i]]++;
    }
    int i;
    for( i=0; i<n; i++){
        if(mark[v[i]] == 1){
            printf("%d",v[i]);
            break;
        }
    }
    if(i==n) printf("None");
}
