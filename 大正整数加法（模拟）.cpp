#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define N 10010
using namespace std;

int main(int argc, char const *argv[])
{
    char a[N] = {'0'};
    char b[N] = {'0'};
    int ans[N];
    int taila;
    int tailb;
    int up = 0;
    int i=0;
    scanf("%s", a+1);
    scanf("%s", b+1);
    taila = (int)strlen(a) - 1;
    tailb = (int)strlen(b) - 1;
    while(tailb > 0 && taila > 0){
        ans[i] = ((a[taila]-'0' + b[tailb]-'0' + up) % 10);
        up = (a[taila]-'0' + b[tailb]-'0' + up) / 10;
        i++;
        tailb--;
        taila--;
    }
    if(taila == 0 && tailb != 0){
        for(int j=tailb;j>0;j--){
            ans[i] = (b[tailb]-'0' + up)%10;
            up = (b[tailb]-'0' + up)/10;
            i++;
            tailb--;
        }
    }else if(tailb == 0 && taila != 0){
        for(int j=taila;j>0;j--){
            ans[i] = (a[taila]-'0' + up)%10;
            up = (a[taila] - '0' + up)/10;
            i++;
            taila--;
        }
    }
    if(up == 1){
            ans[i] = up;
            i++;
        }
    while(i--){
        printf("%d",ans[i]);
    }
    return 0;
}