#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    while(~scanf("%d",&N)){
        int flot=0;
        int x,temp;
        for(int i=N-60;i<=N;i++){
            x=i;temp=0;
            while(x){
                temp+=x%10;
                x/=10;
            }
            if(i+temp==N){
                printf("%d\n",i);
                flot=1;
                break;
            }
        }
        if(!flot){
            puts("0");
        }
    }
    return 0;
}