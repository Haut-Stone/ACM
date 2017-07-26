/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-07 22:07:37
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 10:50:16
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1728
//这道题，偏向数学问题

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;


#define maxn 35
int a[maxn][maxn];//地图

int main ()
{
    int t, n, k, i, j,x;
    int num;
    double  sum;

    scanf ("%d", &t);
    memset (a, 0, sizeof(a));

    for (i=1; i<maxn; i++)//打表，先存储后面运算中需要的组合数
        a[i][1] = i, a[i][0] = 1;

    for (i=2; i<maxn; i++)
        for (j=2; j<maxn; j++)
            a[i][j] = a[i-1][j] + a[i-1][j-1];

    while (t --)
    {
        scanf ("%d %d", &n, &k);
        
        sum = 0;

        for (i=0; i<n; i++)
        {
            num = 0;
            for (j=0; j<n;j++)
            {
                scanf ("%d", &x);
                if (x)
                    num ++;
            }
            for (j=k; j<=num; j++)
                sum += a[num][j] / pow(2,num+1);
        }
        printf ("%.3f\n", sum);
    }
    return 0;
}