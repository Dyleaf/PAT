#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long a,b,c, sum;
    for(int i =1; i<=n; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a+b;
        printf("Case #%d: ", i);
        if(a<0 && b<0 && sum>=0){
            printf("false\n");
        }else if(a>0 && b>0 && sum<=0){
            printf("true\n");
        }else{
            printf("%s\n", sum>c? "true":"false");
        }
    }
}
