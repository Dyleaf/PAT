#include <bits/stdc++.h>
using namespace std;

bool check(int * v, int n,int m)
{
    stack<int> s;
    int cur = 0;
    for(int i=1; i<=n; i++){
        s.push(i);
        if(s.size()>m) break;
        while(!s.empty() && v[cur]== s.top()){
            s.pop();
            cur++;
        }
    }
    return s.size()>0? false:true;
}

int main()
{
    int m,n, k;
    int stack[1010];
    scanf("%d%d%d", &m,&n,&k);
    for(int j=0; j<k; j++)
    {
        for(int i=0; i<n; i++){
        scanf("%d",&stack[i]);
        }
        bool flag =check(stack, n, m);
        printf("%s\n",(flag==true) ? "YES":"NO");
    }
}
