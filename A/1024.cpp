//大数的题可以根据字符串来处理
#include <bits/stdc++.h>
using namespace std;

void add(string &s, string &t){
    int car = 0, i;
    for(i=0; i<s.length(); i++){
        s[i] = s[i]+t[i]+ car-'0';
        car = 0;
        if(s[i]>'9'){
            s[i]-=10;
            car = 1;
        }
    }
    if(car) s += '1';
    reverse(s.begin(), s.end());
}
int main(){
    int cnt, i;
    string s;
    cin>>s>>cnt;
    for(i=0; i<=cnt; i++){
        string t = s;
        reverse(t.begin(), t.end());
        if(t==s || i==cnt) break;
        add(s, t);
    }
    cout<<s<<endl<<i;
}
