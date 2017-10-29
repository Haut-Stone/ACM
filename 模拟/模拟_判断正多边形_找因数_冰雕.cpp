/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-26 18:59:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-26 19:01:06
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

const int N = 20010;

int a[N];

int main(void)
{
    // INPUT_TEST;
    int n;
    while(scanf("%d", &n) != EOF){
        int sum = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        // sum
        int ans = sum;

        // If it is a factor of n can be formed a regular polygon
        for(int i=3;i<=n/2;i++){
            if(n%i) continue;
            int step = n / i;
            for(int k=1;k<=step;k++){
                int temp = 0;
                
                // sum
                for(int j=k;j<=n;j+=step){
                    temp += a[j];
                }
                ans = max(ans, temp);
            }
        }
        printf("%d\n", ans);
    }
}