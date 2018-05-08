#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int main(){
    int n;
    int v[maxn];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }
    sort(v, v+n, greater<int>());
    int i;
    for(i=0; i<n && i+1<v[i]; i++);
    printf("%d", i);
}
