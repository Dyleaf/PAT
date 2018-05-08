//a simple simulate , in this problem use set to mark nodes;
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000;

struct NODE{
    int adr, value, next, show;
}node[maxn];

int main(){
    int first,n;
    scanf("%d%d", &first, &n);
    int adr, value, next;
    set<int>s;
    for(int i=1; i<=n; i++){
       scanf("%d%d%d",&adr,&value, &next );
       node[adr] = {adr, value, next, 1};
    }
    int cur  = first,ansnext=-1, delnext = -1;
    vector<NODE> ans,del;
    while(cur!=-1){
       auto it = s.find(abs(node[cur].value));
       int tmp = node[cur].next;
       if(it!=s.end()){
           node[cur].show = 0;
           node[cur].next = -1;
           if(del.size()>0)
           del[del.size()-1].next = node[cur].adr;
           del.push_back(node[cur]);
       }else {
        node[cur].next = -1;
        if(ans.size()>0)
        ans[ans.size()-1].next = node[cur].adr;
        ans.push_back(node[cur]);
        s.insert(abs(node[cur].value));
       }
       cur = tmp;
    }
    for(int i=0; i<ans.size(); i++){
        if(ans[i].next == -1)
            printf("%05d %d %d\n", ans[i].adr, ans[i].value,ans[i].next);
        else
            printf("%05d %d %05d\n", ans[i].adr, ans[i].value,ans[i].next);
    }
    for(int i=0; i<del.size(); i++){
        if(del[i].next == -1)
            printf("%05d %d %d\n", del[i].adr, del[i].value,del[i].next);
        else
            printf("%05d %d %05d\n", del[i].adr, del[i].value,del[i].next);
    }

}
