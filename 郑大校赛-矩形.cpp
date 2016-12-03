#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n;
    long long x1, x2, x3, x4, y1, y2, y3, y4;
    long long s1;
    long long l,h,s;
    long long x[5];
    long long y[5];
    scanf("%lld", &n);
    while(n--){
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        x[0] = x1;x[1] = x2;x[2] = x3;x[3] = x4;
        y[0] = y1;y[1] = y2;y[2] = y3;y[3] = y4;
        sort(x, x+4);
        sort(y, y+4);
        s1 = fabs((x2-x1)*(y2-y1)) + fabs((x3-x4)*(y3-y4));
        l = fabs(x2-x1) + fabs(x3-x4) - (x[3]-x[0]);
        h = fabs(y2-y1) + fabs(y3-y4) - (y[3]-y[0]);
        s = l*h;
        if(l<=0 || h<=0){
            printf("%lld\n", s1);
        }else{
            printf("%lld\n", s1-s);
        }
    }
    return 0;
}