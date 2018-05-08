#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;


bool isprime(int x){
    if(x <= 1) return false;
    int _sqrt = sqrt((double)x);
    for(int i=2; i<=_sqrt; i++){
        if(x%i==0)
            return false;
    }
    return true;
}
int main(){
    int n, t;
    int v[maxn];
    map<int, int> query;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d", &t);
        v[t] = i;
        query[t]= -1;
    }
    //``sort(v, v+maxn);
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d", &t);
        printf("%04d: ", t);
        if(query[t] == 1) {
            printf("Checked\n");
        }else if(query[t]==-1){
            if(v[t] == 1){
                printf("Mystery Award\n");
            }else if(isprime(v[t])){
                printf("Minion\n");
            }else{
                printf("Chocolate\n");
            }
        }else{
            printf("Are you kidding?\n");
        }
        query[t] = v[t]==0? 0:1;
    }

}
