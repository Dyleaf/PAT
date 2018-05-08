#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

bool IsPrime[maxn];
int Prim[maxn];
int  euler_prime(int n){
    int num = 0, j;
    for(int i = 2; i <= n; i ++){
        if(!IsPrime[i])
            Prim[num ++] = i;
        for(j  = 0; j < num; j ++){
            if(i * Prim[j] > n)
                break;
            IsPrime[i * Prim[j]] = true;
            if(i % Prim[j] == 0)
                break;
        }
    }
}


int convert(int num, int redix){
    int res= 0;
    while(num){
        res *= redix;
        res += num % redix;
        num /= redix;
    }
    return res;
}


int main()
{
    int n, d;
    euler_prime(maxn-1);
    IsPrime[1] =IsPrime[0] = 1;
    while(true){
        scanf("%d", &n);
        if(n<0) break;
        scanf("%d", &d);
        int res =  convert(n,d);
        if(!IsPrime[n] && !IsPrime[res])
            printf("yes\n");
        else
            printf("no\n");
    }
}
