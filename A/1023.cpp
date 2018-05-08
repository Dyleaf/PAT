#include <bits/stdc++.h>
using namespace std;

int mark[10];


int main()
{
    char n[23];
    scanf("%s", n);
    for(int i=0; i<10; i++)mark[i] = 0;

    int c= 0;
    for(int i=strlen(n)-1; i>=0; i--)
    {
        int temp = n[i]-'0';
        mark[temp]++;
        temp = temp*2 + c;
        c = 0;
        if(temp>=10)
        {
            temp -=10;
            c=1;
        }

        mark[temp]--;
        n[i] = temp+'0';
    }

    int flag = 0;
    for(int i = 0; i < 10; i++) {
        if(mark[i] != 0){
            flag = 1;
            break;
        }
    }
    printf("%s", (flag == 1 || c == 1) ? "No\n" : "Yes\n");
    if(c == 1) printf("1");
    printf("%s\n", n);
}
