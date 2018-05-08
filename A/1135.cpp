#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left, *right;
};

vector<int> in;
node * bulid(node * root, int value){
    if(root==NULL){
        root = new node();
        root->val = value;
        root->left = NULL; root->right = NULL;
    }else if(abs(value) <=abs(root->val))
        root->left = bulid(root->left, value);
    else
        root->right = bulid(root->right, value);
    return root;
}

void intravel(node * root){
    if(root ==NULL)return;
    intravel(root->left);
    in.push_back(root->val);
    intravel(root->right);
}

bool judge3(node * root){
    if(root ==NULL) return true;
    if(root->val<0){
        if(root->left !=NULL && root->left->val<0) return false;
        if(root->right != NULL && root->right->val<0) return false;
    }
    return judge3(root->left) && judge3(root->right);
}

int  countNode(node *root){
    if(root == NULL) return 0;
    int l = countNode(root->left);
    int r = countNode(root->right);
    return root->val>0? max(l, r)+1: max(l, r);
}

bool judge4(node *root){
    if(root ==NULL) return true;
    int l = countNode(root->left);
    int r = countNode(root->right);
    if(l != r) return false;
    return judge4(root->left) && judge4(root->right);
}

int main(){

    int Case;
    scanf("%d", &Case);
    while(Case--){
        int n;
        scanf("%d", &n);
        int value;
        node * root = NULL;
        bool flag = true;
        for(int i=0; i<n; i++){
            scanf("%d", &value);
            root = bulid(root, value);
        }
        if(root->val<0){
            flag = false;
        }
        in.clear();
        intravel(root);
        for(int i = 1; i<n; i++){
            if(abs(in[i])<abs(in[i-1])){
                flag = false;
            }
        }
        if(!judge3(root) || !judge4(root)) flag = false;
        if(!flag)
            printf("No\n");
        else printf("Yes\n");
    }
}
