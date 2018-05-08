#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];
int main(){
    string s;
    getline(cin, s);
    int ans = 1;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<s.length(); i++){
        dp[i][i] = 1;
        if(i<s.length() -1 && s[i] == s[i+1]){
            dp[i][i+1] = 1;
            ans  = 2;
        }
    }
    for(int k = 3; k<= s.length(); k++){
        for(int i = 0; i+k-1<s.length(); i++){
            int j = i+k-1;
            if(s[i] == s[j] && dp[i+1][j-1]==1){
                dp[i][j] =1;
                ans = k;
            }
        }
    }
    printf("%d\n", ans);
}
