#include <bits/stdc++.h>
using namespace std;


int main(){
    int game[3];
   double value[3];
    char type[] = {'W', 'T', 'L'};
    double a, b, c;
    for(int i =0; i<3;i++){
        scanf("%lf%lf%lf",&a,&b,&c);

        if(a>b){
            if(a>c){
                game[i] = 0;
                value[i] = a;
            }else{
                game[i] = 2;
                value[i] = c;
            }
        }else{
            if(b>c){
                game[i]  = 1;
                value[i] = b;
            }else{
                game[i] = 2;
                value[i] = c;
            }
        }
    }
    printf("%c %c %c %.2lf\n", type[game[0]], type[game[1]],type[game[2]], (value[0]*value[1]*value[2]*0.65-1)*2);
}
