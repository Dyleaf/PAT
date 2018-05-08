#include <bits/stdc++.h>
using namespace std;

vector<int> pre, pos;
bool ismirror = false;

void getpos(int root, int tail){
    int i=root+1, j = tail;
    if(root>tail) return;
    if(!ismirror){
        while(i<=tail && pre[i]<pre[root]) i++;
        while(j> root && pre[j]>=pre[root]) j--;
    }else{
        while(i<=tail && pre[i]>=pre[root]) i++;
        while(j> root && pre[j]<pre[root]) j--;
    }
    if(i-j != 1) return;
    getpos(root+1, j);
    getpos(i, tail);
    pos.push_back(pre[root]);
}


int main(){
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i =0; i<n; i++)
        scanf("%d", &pre[i]);
    getpos(0, n-1);
    if(pos.size() != n) {
        ismirror = true;
        pos.clear();
        getpos(0, n-1);
    }
    if(pos.size()==n){
        printf("YES\n");
        for(int i=0; i<n; i++){
            if(i!=0) printf(" ");
            printf("%d",pos[i]);
        }
    }else{
        printf("NO");
    }
    return 0;
}
