//水题。不过在处理进制的时候最高位作开始用科学计数法卡了
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n[2][3], maxn[3] = {0, 17,29};
    for(int i=0; i<2; i++){
        scanf("%lld.%lld.%lld", &n[i][0], &n[i][1],&n[i][2]);
    }
    int carry = 0;
    for(int i=2; i>0; i--){
        n[1][i] = n[1][i]+n[0][i]+carry;
        carry = 0;
        if(n[1][i]>=maxn[i]){
            carry=n[1][i]/maxn[i];
            n[1][i]%=maxn[i];
        }
    }
    n[1][0] = n[1][0]+n[0][0]+carry;
    printf("%lld.%lld.%lld\n",n[1][0], n[1][1], n[1][2]);
}
