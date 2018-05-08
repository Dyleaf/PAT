#include <bits/stdc++.h>
using namespace std;


const int maxn = 200;

int main()
{
    int n, b;
    int num[maxn];

    while(scanf("%d%d", &n, &b)!=EOF)
    {
        int i= 0;
        if(n==0) num[i++] = 0;
        while(n){
            num[i++] = n%b;
            n/=b;
        }
        int flag = 1;
        for(int x = 0, y = i-1; x<y;x++, y--)
        {
            if(num[x]!=num[y])
                flag = 0;
        }
        if(flag)printf("Yes\n");
        else printf("No\n");

        for(i--; i>=0;i--){
            if(i==0) printf("%d\n", num[i]);
            else  printf("%d ", num[i]);
        }
    }
}
