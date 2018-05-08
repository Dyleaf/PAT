#include <bits/stdc++.h>
using namespace std;

int main(){

    int  cur = 0, n, next,tol =0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &next);
        if(next>cur){
            tol+=(next-cur)*6+5;
            cur = next;
        }else if(cur> next){
            tol+=(cur-next)*4+5;
            cur = next;
        }else if(cur == next){
            tol+=5;
        }
    }
    printf("%d\n", tol);
}
