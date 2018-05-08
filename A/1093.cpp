#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int maxn = 100010;

int main(){
    char s[maxn];
    int leftP[maxn];
    gets(s);
    int len = strlen(s);
    for(int i=0; i<len; i++){
        if(i>0) leftP[i] = leftP[i-1];
        if(s[i] == 'P') leftP[i]++;
    }
    int ans = 0, rightT = 0;
    for(int i=len -1; i>=0; i--){
        if(s[i] == 'T'){
            rightT++;
        }else if(s[i] == 'A'){
            ans = (ans + leftP[i]*rightT)%MOD;
        }
    }
    printf("%d", ans);
}
