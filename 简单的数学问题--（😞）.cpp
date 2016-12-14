#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    long long s;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &s);
        long long number1;
        number1 = sqrt(s) + 1;
        for(long long i=number1;i>0;i--){
            if(s%i == 0){
                printf("%lld\n", (i+s/i)*2);
                break;
            }
        }
    }
    return 0;
}