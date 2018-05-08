// 水题
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int len = s.length(), l = 0, r = s.length()-1;
    int n1 = (2+len)/3;
    int n2 = len+2 -2*n1;
    for(; l<n1; l++,r--){
        printf("%c", s[l]);
        for(int i=0; i<n2-2; i++)
            if(l!=n1-1)
                printf(" ");
            else
                printf("%c",s[i+l+1]);
        printf("%c\n",s[r]);
    }
}
