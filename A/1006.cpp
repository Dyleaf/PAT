#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    int m;
    scanf("%d", &m);
    char id_open[16], id_close[16], t_open[] = "23:59:59", t_close[] = "00:00:00";
    char id[16], arrive[9], depart[9];
    for (int i = 0; i < m; i++) {
        scanf("%s %s %s", id, arrive, depart);
        if (strcmp(t_open, arrive) > 0) {
            strcpy(id_open, id);
            strcpy(t_open, arrive);
        }
        if (strcmp(t_close, depart) < 0) {
            strcpy(id_close, id);
            strcpy(t_close, depart);
        }
    }
    printf("%s %s\n", id_open, id_close);
    return 0;
}
