#include <bits/stdc++.h>
using namespace std;
const int INF = 0xfffffff;
const int maxn = 100001;
int mark[maxn]={0};
int main(){
    int n, m, min = INF, tmp;
    scanf("%d%d",&n, &m );
    for(int i=0;i<n; i++){
        scanf("%d", &tmp);
        mark[tmp]++;
    }
    for(int i=0; i<maxn; i++){
        if(mark[i]) {
            mark[i]--;
            if(m> i && mark[m-i]){
                printf("%d %d", i, m-i);
                return 0;
            }
            mark[i]++;
        }
    }
    printf("No Solution\n");
    return 0;
}
