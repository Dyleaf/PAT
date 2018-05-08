#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7FFFFFFF;
const int maxn = 1e5 + 15;
char s[maxn];

int main()
{
    scanf("%s", s);
    int start = s[0] == '-' || s[0] == '+';
    if (s[0] == '-') printf("-");
    string ans = "";
    int point = 0, add = 0;
    while (s[start] != 'E')
    {
        if (s[start] == '.') point = ans.size();
        else ans += s[start];
        start++;
    }
    start++;
    for (int i = start + 1; s[i]; i++) add = add * 10 + s[i] - '0';
    if (s[start] == '-') add = -add;
    if (point + add < 0) printf("0.");
    for (int i = point + add; i < 0; i++)
    {
        printf("0");
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == point + add) printf(".");
        printf("%c", ans[i]);
    }
    for (int i = ans.size(); i < point + add; i++)
    {
        printf("0");
    }
    return 0;
}
