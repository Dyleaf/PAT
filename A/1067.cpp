#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int v[maxn];
int main(){
    int n, cur = 1, ans = 0, tmp;
    int cnt = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        v[tmp] = i;
        if(tmp != i && tmp !=0) cnt++;
    }
    while(cnt>0){
        if(v[0] ==0){
            while(v[cur] == cur)
                cur++;
            swap(v[0],v[cur]);
            ans++;
            cur++;
        }else{
            swap(v[0], v[v[0]]);
            cnt--;
            ans++;
        }
    }
    printf("%d\n", ans);
}
