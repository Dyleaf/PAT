#include <bits/stdc++.h>
using namespace std;


int main(){
    int n , cnt = 0;
    double tol=0,tmp = 0;
    char s[20];
    scanf("%d", &n);
    for(int i =  0; i< n; i++){
        scanf("%s", s);
        tmp = 0;
        int j,point = 0,afpoint = 0,fu = 0, len = strlen(s);
        double base = 10;
        for(j = 0; j<len; j++){
            if(s[j]=='-'){
                fu++;
                if(fu>1 || j!=0) break;
                continue;
            }
            if(isdigit(s[j])){
                if(point == 0){
                    tmp = tmp*base + s[j]-'0';
                }
                else{
                    tmp = tmp + base*(s[j] -'0');
                    base *=0.1;
                    afpoint++;
                }
            }else if(s[j] =='.'){
                point++;
                base = 0.1;
                if(point>1 || j==0) break;
            }else{
                break;
            }
        }
        if(j !=len ||  tmp>1000 || tmp<-1000 || afpoint>2){
            printf("ERROR: %s is not a legal number\n", s);
        }else{
            cnt++;
            tol = fu==1? tol-tmp: tol+tmp;
        }
    }
    cout << "The average of " << cnt;
    if(cnt == 1)
        cout << " number is ";
    else
        cout << " numbers is ";
    if(cnt == 0)
        cout << "Undefined";
    else
        printf("%.2lf",tol/cnt);
}
