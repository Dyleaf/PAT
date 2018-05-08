#include <bits/stdc++.h>
using namespace std;

char c[14] = {"0123456789ABC"};
int main(){
    printf("#");
    for(int i=0; i<3; i++){
        int n;
        scanf("%d", &n);
        printf("%c%c",c[n/13], c[n%13]);
    }
}
