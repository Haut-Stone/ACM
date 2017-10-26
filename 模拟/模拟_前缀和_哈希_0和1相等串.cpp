/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-26 07:36:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-26 07:49:47
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;


const int N = 1000010;
char a[N];
int sum[N];
int neg[N];
int pos[N];

int main(void)
{
    scanf("%s", a+1);
    int ans = 0;
    int len = strlen(a+1);

    //input and calculate the prefix sum
    for(int i=1;i<=len;i++){
        int b = (a[i] - '0');
        if(b == 0) b = -1;
        sum[i] = sum[i-1] + b;
    }

    //hash
    pos[0] = -1;
    for(int i=1;i<=len;i++){
        if(sum[i] >= 0){
            if(pos[sum[i]] == 0){
                pos[sum[i]] = i;
            }else{
                if(sum[i] == 0){
                    ans = max(ans, i - pos[sum[i]] - 1);
                }else{
                    ans = max(ans, i - pos[sum[i]]);
                }
            }
        }else{
            if(neg[-sum[i]] == 0){
                neg[-sum[i]] = i;
            }else{
                ans = max(ans, i - neg[-sum[i]]);
            }
        }
    }
    printf("%d\n", ans);
}