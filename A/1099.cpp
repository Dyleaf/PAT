#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct NODE{
    int value, left, right;
}tree[1000];

int cnt = 0;

void midTravel(int root, int * key){
    if(tree[root].left !=-1 )
       midTravel(tree[root].left, key);
    tree[root].value = key[cnt++];
    if(tree[root].right !=-1 )
        midTravel(tree[root].right, key);
}
bool first = true;
void leaveTravel(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(tree[tmp].left != -1)
            q.push(tree[tmp].left);
        if(tree[tmp].right != -1)
            q.push(tree[tmp].right);
        if(!first)
            printf(" ");
        else
            first = false;
        printf("%d", tree[tmp].value);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int left, right, key[1000];
    for(int i = 0; i<n; i++){
            scanf("%d%d", &left, &right);
            tree[i].left = left;
            tree[i].right = right;
    }
    for(int i=0; i<n; i++){
        scanf("%d", &key[i]);
    }
    sort(key, key+n);
    midTravel(0, key);
    leaveTravel(0);
}
