#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    struct node *left, *right;
};

node *rotateleft(node *root) {
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t;
}

node *rotateright(node *root) {
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rotateleftright(node *root) {
    root->left = rotateleft(root->left);
    return rotateright(root);
}
node *rotaterightleft(node *root) {
    root->right = rotateright(root->right);
    return rotateleft(root);
}
int getheight(node *root) {
    if(root == NULL) return 0;
    return max(getheight(root->left), getheight(root->right)) + 1;
}
node *insert(node *root, int val) {
    if(root == NULL) {
        root = new node();
        root->val = val;
        root->left = root->right = NULL;
    } else if(val < root->val) {
        root->left = insert(root->left, val);
        if(getheight(root->left) - getheight(root->right) == 2)
            root = val < root->left->val ? rotateright(root) : rotateleftright(root);
    } else {
        root->right = insert(root->right, val);
        if(getheight(root->left) - getheight(root->right) == -2)
            root = val > root->right->val ? rotateleft(root) : rotaterightleft(root);
    }
    return root;
}
bool complate = true;
vector<int> leavelOrder(node * root){
    queue<node *> q;
    vector<int> v;
    q.push(root);
    bool mark = false;
    while(!q.empty()){
        node * tmp = q.front();
        q.pop();
        v.push_back(tmp->val);
        if(tmp->left !=NULL){
            q.push(tmp->left);
            if(mark)
                complate = false;
        }else mark = true;
        if(tmp->right !=NULL){
            q.push(tmp->right);
            if(mark)
                complate = false;
        }else mark = true;
    }
    return v;
}
int main() {
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    vector<int> v = leavelOrder(root);
    for(int i=0; i<v.size(); i++){
        if(i!=0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n%s", complate? "YES":"NO");
    return 0;
}
