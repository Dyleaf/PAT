#include <bits/stdc++.h>
using namespace std;

const int  maxn = 100;
char week[8][4] = {"", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    char s1[maxn], s2[maxn], s3[maxn], s4[maxn];
    cin>s1>>s2>>s3>>s4;
    cout<<"33";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int len3 = strlen(s3);
    int len4 = strlen(s4);
    int flag = 0;
        cout<<"end"<<len1<<len2<<len3<<len4<<endl;;
    for(int i=0; i< len1 && i< len2; i++)
    {
        if(s1[i] == s2[i] && flag == 0){
            flag++;
            cout<<week[s1[i]-'a'+1]<<" ";
        }else if(s1[i] == s2[i] && flag ==1){
            if(s1[i]>'9')
                printf("%02d",s1[i]-'a'+10);
            else
                printf("%02d",s1[i]-'0');
            break;
        }
    }
    for(int i=0; s3[i]!='\0' && s4[i]!='\0'; i++){
        if(s3[i] == s4[i])
            printf(":%02d\n", i);
    }
}
