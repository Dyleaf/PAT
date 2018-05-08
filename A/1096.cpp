//思路：由于12!大于2^31，所以连续的因子最多有10个（2~11）。那么就从2开始一直到sqrt(n)，每次取连续i（10~1）个数相乘，如果能整除n的话，就说明是最长的序列
#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    int sqr = sqrt(n);
    for(int len=10; len>0; len--){
        for(int i = 2;i<=sqr; i++){
            long long tmp = 1;
            for(int j=0; j<len; j++){
                tmp*=(j+i);
            }
            if(n%tmp==0){
                printf("%d\n", len);
                for(int k =0; k<len-1; k++){
                    printf("%d*",i+k);
                }
                printf("%d\n",i+len-1);
                return 0;
            }
        }
    }
    printf("1\n%d",n);
    return 0;
}
