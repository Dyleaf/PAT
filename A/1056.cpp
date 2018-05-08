#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000;

struct Mouse{
    int weight;
    int order;
}mouse[maxn];

int cmp(int begin, int m)
{
    int k = begin;
    for(int i=begin; i<begin+m; i++){
        if(mouse[i].weight> mouse[k].weight)k = i;
    }
    return k;
}
int main()
{
    int n, m;
    queue<int> order;

    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &mouse[i].weight);
        mouse[i].order= -1;
    }
    int x;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        order.push(x);
    }

    int group = n, max;
    while(order.size() > 1) {
        group = group%m==0? group/m: group/m+1;
        queue<int> tmp;
        for(int i=0; i<group; i++)
        {
            int t = 0, cur;
            max = order.front();
            while(t<m)
            {
                t++;
                if(order.size()==0) break;
                cur  = order.front();
                order.pop();
                mouse[cur].order = group +1;
                if(mouse[max].weight < mouse[cur].weight) max = cur;
            }
            mouse[max].order = -1;
            tmp.push(max);
        }
        order = tmp;
    }
    mouse[max].order = 1;
    for (int i = 0; i<n; i++){
        if(i==n-1)printf("%d\n", mouse[i].order);
        else printf("%d ", mouse[i].order);
    }
}
