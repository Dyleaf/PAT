#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num,t;
    cin>>n;
    set<int> s;
    for(int i =0; i<n; i++)
    {
        cin>>num;
        t = 0;
        while(num){
            t+=num%10;
            num/=10;
        }
        s.insert(t);
    }
    cout<<s.size()<<endl;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        if(it==s.begin())cout<<*it;
        else cout<<" "<<*it;
    }
    cout<<endl;
    return 0;
}
