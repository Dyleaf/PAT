#include <bits/stdc++.h>
using namespace std;

string a1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string a2[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


void fun1(string s){
    int num = 0;
    for(int i =0; i<s.length(); i++){
        num *= 10;
        num +=s[i]-'0';
    }
    cout<<a2[num/13];
    if(num>13 && num%13) cout<<" "<<a1[num%13]<<endl;
    else if(num%13==0 && num) cout<<endl;
    else cout<<a1[num%13]<<endl;
}

void fun2(string s){
    int len = s.length(), num = 0;
    if(len==4){
        cout<<0<<endl;
        return ;
    }else if(len==3){
        for(int i =0; i<=12; i++){
            if(a1[i] == s){
                cout<<i<<endl;
                return;
            }
            if(a2[i] == s){
                cout<<i*13<<endl;
                return;
            }
        }
    }else {
        string a = s.substr(0, 3), b = s.substr(4, 3);
        for(int i =0; i<=12; i++){
            if(b==a1[i]) num+=i;
            if(a == a2[i]) num +=i*13;
        }
        cout<<num<<endl;
    }
    return ;
}
int main()
{
    int i;
    string s;
    cin>>i;
   // getchar();
    while(i--)
    {
        getline(cin,s);
        if(isdigit(s[0])){
            fun1(s);
        }else {
            fun2(s);
        }
    }
}
