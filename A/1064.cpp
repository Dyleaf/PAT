#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
int node[maxn],level[maxn];

void levelorder(int left, int right, int idx){
    if(left>right) return;
    int n = right -left+1;
    int l = log(n+1)/log(2);
    int leave = n-pow(2,l)+1;
    int root = left + pow(2, l-1)-1 +min((int)pow(2, l-1), leave);
    // througu idx to get leave order;
    level[idx] = node[root];
    levelorder(left, root-1, idx*2);
    levelorder(root+1, right, idx*2+1);
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1; i<= n; i++){
        scanf("%d", &node[i]);
    }
    sort(node+1, node+n+1);
    levelorder(1,n, 1);
    for(int i=1; i<=n ;i++){
        if(i!=1) printf(" ");
        printf("%d",level[i]);
    }
    return 0;
}
