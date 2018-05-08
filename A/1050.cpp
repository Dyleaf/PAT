#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;
int mark[256];

int main(){
    char a[maxn], b[maxn];
    gets(a);
    gets(b);
    int alen = strlen(a), blen = strlen(b);
    for(int i=0; i<blen; i++){
        mark[b[i]]++;
    }
    for(int i=0; i<alen; i++){
        if(mark[a[i]]) continue;
        putchar(a[i]);
    }
}
