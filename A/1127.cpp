#include <bits/stdc++.h>
using namespace std;
const int maxn=42;
int in[maxn],pos[maxn],h=-1;

vector<int> v[maxn];

void bulid(int inL,int inR,int poL,int poR,int level)
{
    if(inL>inR) return;
    h=(h<level)?level:h;
    v[level].push_back(pos[poR]);
    int e=pos[poR],i=inL;
    while(i<=inR&&e!=in[i]) ++i;
    bulid(inL,i-1,poL,poL+i-1-inL,level+1);
    bulid(i+1,inR,poL+i-inL,poR-1,level+1);
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) scanf("%d",&in[i]);
    for(int i=0;i<n;++i) scanf("%d",&pos[i]);
    bulid(0,n-1,0,n-1,1);
    printf("%d", pos[n-1]);
    for(int j=2;j<=h;++j)
    {
        if(j&1)
            for(int i=v[j].size()-1; i>=0; i--)
                printf(" %d", v[j][i]);
        else
            for(int i=0; i<v[j].size(); i++)
                printf(" %d", v[j][i]);
    }
    return 0;
}
