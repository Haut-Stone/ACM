/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-25 10:46:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-25 10:49:22
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define LL long long
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

long long x, y;
long long n, a, b;

long long exGcd(long long a, long long b, long long &x, long long &y)
{
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    long long gcd = exGcd(b, a%b, x, y);
    long long temp = x;
    x = y;
    y = temp - (a/b) * y;
    return gcd;
}

int main(void)
{
    INPUT_TEST;
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld %lld", &n, &a, &b);
        long long ans = 0;
        long long d = exGcd(a, b, x, y);
        long long c = a*b/d;
        if((1+n) % d){
            ans = 0;
        }else{
            x = x*((1+n) / d);
            long long r = b/d;
            x = (x%r + r) % r;
            if(x == 0){
                x += r;
            }
            long long res = n-(x)*a;
            if(res < 0){
                ans = 0;
            }else{
                ans++;
                ans += res/c;
            }
        }
        printf("%d\n", ans);
    }
}
