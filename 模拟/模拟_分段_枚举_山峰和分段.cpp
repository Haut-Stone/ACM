/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-25 08:54:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-25 09:00:28
*/

#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)

using namespace std;
const int N = 50050;

int point[N];//点的高度
int pre[N];//记录该点和之前的山峰总数
int peak[N];//标记一个点是否是山峰， peak[0]代表山峰的总数


int main(void)
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &point[i]);
    }
    for(int i=2;i<n;i++){
        if(point[i-1] < point[i] && point[i] > point[i+1]){
            peak[0]++;
            peak[i] = 1;
        }
    }
    for(int i=2;i<=n;i++){
        pre[i] = pre[i-1];
        if(peak[i]){
            pre[i]++;
        }
    }

    bool ok = true;
    int ans = 0;
    for(int i=peak[0];i>=1;i--){
        if(n % i != 0) continue;
        ans = i;
        ok = true;
        int z = n/i;
        int j=z;
        for(;j<=n;j+=z){
            if(pre[j] - pre[j-z] == 0){
                ok = false;
                break;
            }
        }
        if(j > n){
            break;
        }
    }
    if(ok){
        printf("%d\n", ans);
    }
}
