#include <bits/stdc++.h>
using namespace std;

bool isprime(int x){
    int _sqrt = sqrt(x);
    if(x<=1) return false;
    for(int i=2; i<=_sqrt; i++){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    int tsize, n,m,a, idx;
    scanf("%d%d%d", &tsize, &n,&m);
    while(!isprime(tsize)) tsize++;
    vector<int> v(tsize);
    for(int i=0; i<n; i++){
        scanf("%d",&a);
        bool flag = false;
        for(int j=0; j<tsize; j++){
            idx= (j*j + a)%tsize;
            if(v[idx]==0){
                v[idx] = a;
                flag = true;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n",a);
    }
    double ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a);
        int cnt = 1;
        for (int j = 0; j < tsize; j++) {
            int idx = (a + j * j) % tsize;
            if (v[idx] == a || v[idx] == 0) break;
            cnt++;
        }
        ans += cnt;
    }
    printf("%0.1lf",ans/m);
}
