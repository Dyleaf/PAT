// 拓扑排序
// 很玄学 为什么最开始的vector设置为 vector< vector<int> > 的形式卡在最后一个点
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int main(){
    int n,m,k,a,b, in[maxn],first = true;
    scanf("%d%d", &n,&m);
    vector<int> v[maxn];
    for(int i=0; i<m; i++){
        scanf("%d%d", &a,&b);
        v[a].push_back(b);
        in[b]++;
    }
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        int judge = 1;
        vector<int> tin(in,in+n+1);
        for(int j=0; j<n; j++){
            scanf("%d",&a);
            if(tin[a]!=0){
                judge = 0;
            }
            for(int it:v[a]) tin[it]--;
        }
        if(judge == 1) continue;
        printf("%s%d",first? "":" ",i);
        first = false;
    }
    return 0;
}
