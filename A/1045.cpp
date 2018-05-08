#include<bits/stdc++.h>
using namespace std;

const int maxn = 10010;

int main(){
    int n,m;
    int book[maxn], v[maxn], dp[maxn];
    int len,x, cnt = 0;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++){
        scanf("%d", &x);
        book[x] = i;
    }
    scanf("%d", &len);
    for(int i=0; i<len; i++){
        scanf("%d", &x);
        if(book[x]>=1){
            v[cnt++] = book[x];
        }
    }
    int mmax = 0;
    for(int i=0; i<cnt; i++){
        dp[i] = 1;
        for(int j =0; j<i; j++){
            if(v[i] >= v[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        mmax = max(mmax, dp[i]);
    }
    printf("%d",mmax);
}
