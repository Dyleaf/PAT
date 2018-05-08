#include <bits/stdc++.h>
using namespace std;
bool cmp(char a, char b){
    return a>b;
}
int main(){
    string a, b;
    int ans;
    cin>>a;
    ans = -1;
    a.insert(0,4-a.length(), '0');
    while(ans!=6174 && ans!=0){
        sort(a.begin(), a.end(),cmp);
        b = a;
        reverse(b.begin(), b.end());
        ans = stoi(a)-stoi(b);
        printf("%s - %s = %04d\n",a.c_str(),b.c_str(),ans);
        a = to_string(ans);
        a.insert(0,4-a.length(), '0');
    }
}
