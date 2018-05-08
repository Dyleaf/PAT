#include <bits/stdc++.h>
using namespace std;
int mark[256];
int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++)
        mark[a[i]]++;
    int result = 0;
    for (int i = 0; i < b.length(); i++) {
        if (mark[b[i]] > 0)
            mark[b[i]]--;
        else
            result++;
    }
    if(result != 0)
        printf("No %d", result);
    else
        printf("Yes %d", a.length() - b.length());
    return 0;
}
