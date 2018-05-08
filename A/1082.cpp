#include <bits/stdc++.h>
using namespace std;


char num[10][10] = {"ling","yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
char jie[4][10] = {"", "Shi", "Bai", "Qian"};
char s[100];
bool first = true;

void read(int idx, int len){
    if(len ==0) return ;
    if(s[idx] == '0'){
        bool allzero = true;
        int cnt = 0;
        for(int i =idx; i<len+idx;i++){
            if(s[i] != '0'){
                allzero = false; break;
            }else{
                cnt++;
            }
        }
        if(!allzero) {
            printf(" ling");
            read(idx+cnt, len-cnt);
        }
    }else{
        if(!first) printf(" ");
        else first = false;

        printf("%s",num[s[idx] -'0'] );
        if(len>1) printf(" %s", jie[len-1]);
        read(idx+1, len-1);
    }
}
int main(){
    cin>>s;
    int cnt = 0, len = strlen(s);
    if(s[cnt] == '-'){
        cnt++; cout<<"Fu ";
        first =true;
        len--;
    }
    int a = atoi(s);
    if(a == 0){
        printf("ling");
        return 0;
    }
    if(len>=9){
        if(!first) printf(" ");
        printf("%s Yi", num[s[cnt] - '0']);
        cnt++;len--;
        first = false;
    }
    if(5<=len && len<=8){
        read(cnt, len -4);
        cnt +=len-4;
        len=4;
        printf(" Wan");
    }
    if(1<=len && len<=4){
        read(cnt, len);
    }
}
