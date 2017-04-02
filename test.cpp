/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-02 20:48:46
*/
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

#define INF 0x3f3f3f3f //定义无穷数 
const int MAXN = 2000+17;  //定义最大数
char s[MAXN][17];  //存储车辆的信息

int m[MAXN][MAXN];  
int low[MAXN], visited[MAXN];  
int n;  
  

int prim()  
{  
    int i, j;  
    int pos, minn, result = 0;  
    memset(visited,0,sizeof(visited));  
    visited[0] = 1;  
    pos = 0;  
    for(i = 0; i < n; i++)  
    {  
        low[i] = m[pos][i];  
    }  
    for(i = 0; i < n-1; i++)  
    {  
        minn = INF;  
        pos = -1;  
        for(j = 0; j < n; j++)  
        {  
            if(!visited[j] && low[j] < minn)  
            {  
                minn = low[j];  
                pos = j;  
            }  
        }  
        result += minn;  
        visited[pos] = 1;  
        for(j = 0; j < n; j++)  
        {  
            if(!visited[j] && low[j]>m[pos][j])  
                low[j] = m[pos][j];  
        }  
    }  
    return result;  
}  
int main()  
{  
    while(scanf("%d",&n) && n)  //车辆的个数
    {  
        memset(m,0,sizeof(m));  //初始化
        int ans = prim();  
        printf("The highest possible quality is 1/%d.\n",ans);  
    }  
    return 0;  
}