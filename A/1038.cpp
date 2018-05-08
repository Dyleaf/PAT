// 第一次卡点是没有意识到最后的结果是0的情况
#include <bits/stdc++.h>
using namespace std;

bool cmp(string  a, string b){
    return a+b<b+a;
}
int main(){
    int n;
    vector<string>v;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end(), cmp);
    string s;
    for(int i = 0; i < n; i++)
        s += v[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0) cout << 0;
    cout << s;
}
