#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<long long, int >color;
    int n, m;
    scanf("%d%d",&m, &n);
    for(int i=0; i<n; i++)
    {
        for(int i=0; i<m; i++)
        {
            long long  p;
            scanf("%lld",&p);
            if(color.find(p) == color.end()) color[p]=  1;
            else color[p]++;
        }
    }
    int flag= 0;
    long long  domain;
    for(auto it = color.begin(); it!=color.end();it++)
    {
        if(it->second >flag)
        {
            flag = it->second;
            domain = it->first;
        }
    }

    printf("%lld\n", domain);
}
