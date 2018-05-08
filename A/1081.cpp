// 分数的四则运算
#include <bits/stdc++.h>
using namespace std;

struct fraction{
    long long up,down;
};

long long gcd(long long a, long long b) {return b == 0 ? abs(a) : gcd(b, a % b);}
fraction reduction( fraction res){
    if(res.down<0){
        res.down*=-1;
        res.up*=-1;
    }
    if(res.up == 0){
        res.down = 1;
    }else{
        int d = gcd(abs(res.up), abs(res.down));
        res.up/=d;
        res.down/=d;
    }
    return res;
}
fraction add(fraction f1, fraction f2){
    fraction res;
    res.up = f1.up * f2.down + f2.up * f1.down;
    res.down = f1.down * f2.down;
    return reduction(res);
}

int main(){
    int n;
    scanf("%d", &n);
    fraction a, ans = {0,1};
    for(int i=0; i<n; i++){
        scanf("%lld/%lld", &a.up, &a.down);
        ans =  add(ans, a);
    }
    bool flag = false;
    if(ans.up>ans.down){
        printf("%lld", ans.up/ans.down);
        ans.up = ans.up%ans.down;
        if(ans.up)
            printf(" %lld/%lld",ans.up, ans.down);
        return 0;
    }
    if(ans.up==0)
        printf("0\n");
    else
        printf("%lld/%lld",ans.up, ans.down);

}
