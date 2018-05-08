#include <bits/stdc++.h>
using namespace std;


struct node{
    int id;
    int left;
    int right;
}node[100];

int n;
int pos[100];
int inv[100];


int rebuit(int* pos, int * in, int size){

    if(size==0) return -1;

    int cur = pos[size-1]; //id作为编号

    node[cur].id = pos[size-1];

    int i;
    for(i=0;i<size;i++){
        if(pos[size-1]==in[i])
            break;
    }

    node[cur].left = rebuit(pos,in, i);
    node[cur].right = rebuit(pos+i, in+i+1, size-i-1);
    return node[cur].id;
}


void trval(int root){
    queue<int>tree;
    tree.push(root);
    int cur = -1;
    bool flag = true;
    while(!tree.empty()){
        cur = tree.front();
        tree.pop();
        if(cur ==-1) continue;
        if(flag) printf("%d", cur), flag = false;
        else
        printf(" %d", cur);
        if(node[cur].left!=-1) tree.push(node[cur].left);

        if(node[cur].right!=-1) tree.push(node[cur].right);
    }
    printf("\n");
}


int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d",&pos[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d",&inv[i]);
    }

    rebuit(pos, inv, n);
    trval(pos[n-1]);

}
