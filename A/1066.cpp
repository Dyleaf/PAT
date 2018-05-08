#include <bits/stdc++.h>
using namespace std;

struct NODE{
    int element;
    int height;
    NODE * left, * right;
    NODE(){
        left = NULL;
        right = NULL;
        height = 0;
    }
};
int getheight(NODE * x){
    if(x==NULL)
        return -1;
    else
        return x->height;
}

NODE * LLrotation(NODE * x){
    NODE * left = x->left;
    x->left = left->right;
    left->right = x;
    // above is ll
    x->height = max(getheight(x->left), getheight(x->right))+1;
    left->height = max(getheight(left->left), getheight(left->right))+1;
    return left;
}

NODE * RRrotation(NODE * x){
    NODE * right = x->right;
    x-> right = right->left;
    right->left = x;
    x->height = max(getheight(x->left), getheight(x->right))+1;
    right->height = max(getheight(right->left), getheight(right->right))+1;
    return right;
}

NODE * RLrotation(NODE *x ){
    NODE * right= x->right;
    x->right = LLrotation(right);
    return RRrotation(x);
}

NODE * LRrotation(NODE * x){
    NODE * left = x->left;
    x->left = RRrotation(left);
    return LLrotation(x);
}

NODE * insertNODE(NODE *target, int node){
    if(target==NULL){
        target = new NODE;
        target->element = node;
    }else if(node<target->element){
        target->left = insertNODE(target->left, node);
        int left = getheight(target->left);
        int right = getheight(target->right);
        if(left-right>1){
            if(node < target->left->element){
                target = LLrotation(target);
            }else{
                target = LRrotation(target);
            }
        }else{
            target->height = max(left,right)+1;
        }
    }else {
        target->right = insertNODE(target->right, node);
        int left = getheight(target->left);
        int right = getheight(target->right);
        if(left-right<-1){
            if(node<target->right->element){
                target = RLrotation(target);
            }else{
                target = RRrotation(target);
            }
        }else{
            target->height = max(left,right)+1;
        }
    }
    return target;
}

int main(){
    int n;
    scanf("%d", &n);
    NODE * root = NULL;
    while(n--){
        int node;
        scanf("%d",&node);
        root = insertNODE(root, node);
    }
    printf("%d", root->element);
}
