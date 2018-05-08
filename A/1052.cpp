#include <bits/stdc++.h>
using namespace std;

const int inf = 0x7fffffff;

struct Node{
    int adr;
    int next;
    int key;
    bool flag;
}node[100010];

bool cmp(Node a, Node b){
    return !a.flag || !b.flag ? a.flag> b.flag : a.key< b.key;
}

int main(){

    int n, adr, flag, next, key, base;
    scanf("%d%d",&n,&base);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d", &adr, &key, &next);
        node[adr] = {adr, next, key, false};
    }
    int cur = 0;
    while(base !=-1){
        node[base].flag = true;
        base = node[base].next;
        cur++;
    }

    sort(node, node+100010, cmp);
    if(cur==0) printf("0 -1\n");
    else{
        printf("%d %05d\n",cur, node[0].adr);
        for(int i=0; i<cur; i++){
            printf("%05d %d ",node[i].adr, node[i].key);
            if(i == cur-1) printf("-1\n");
            else printf("%05d\n",node[i+1].adr);
        }
    }
}
