#include <bits/stdc++.h>

using namespace std;

struct Node {
    char name[12];
    char pwd[12];
};

char conver(char &c) {
    if (c == '1') return '@';
    else if (c == '0') return '%';
    else if (c == 'l') return 'L';
    else if (c == 'O') return 'o';
    else return c;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int cnt = 0;
        vector<Node> r(n);
        char c, name[12], pwd[12];
        for (int j = 0; j < n; j++) {
            scanf("%s %s", name, pwd);
            int len = strlen(pwd), flag = 0;
            for (int i = 0; i < len; i++) {
                c = conver(pwd[i]);
                if (c != pwd[i]) {
                    flag = 1;
                    pwd[i] = c;
                }
            }
            if (flag) {
                strcpy(r[cnt].name, name);
                strcpy(r[cnt++].pwd, pwd);
            }
        }
        if (cnt > 0) {
            printf("%d\n", cnt);
            for (int i = 0; i < cnt; i++) {
                printf("%s %s\n", r[i].name, r[i].pwd);
            }
        } else if(n==1){
            printf("There is %d account and no account is modified\n", n);
        }else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    }
}
