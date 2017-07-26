/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-08 20:16:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 20:53:04
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1875
//这不是一道单纯的搜索题，而是双线dp或者记忆化搜索。

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

#define INPUT_TEST freopen("in.txt", "r", stdin)
#define max4(a,b,c,d) max(max(a,b),max(c,d))

const int N = 110;

int row, col;
int ans;
int Imap[N][N];
int dp[2*N][N][N];

void read()
{
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            scanf("%d", &Imap[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
}

int dfs(int k, int x1, int x2)//k表示某个点的横纵坐标相加之和-2
{   
	int y1 = k+2-x1;
	int y2 = k+2-x2;

    if(dp[k][x1][x2]) return dp[k][x1][x2];
    if(k==0 || x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) return dp[k][x1][x2];
    dp[k][x1][x2] = max4(dfs(k-1, x1-1, x2), dfs(k-1, x1, x2-1), dfs(k-1, x1-1, x2-1), dfs(k-1, x1, x2));
    if(x1 != x2){
        dp[k][x1][x2] += Imap[x1][y1] + Imap[x2][y2];
    }else{
        dp[k][x1][x2] += Imap[x1][y1];
    }
    return dp[k][x1][x2];
}

int main()
{   
    INPUT_TEST; 

    int T;
    cin>>T;
    while(T--){
        read();
        dp[0][1][1] = Imap[1][1];
        ans = dfs(row+col-2, row, row);
        printf("%d\n", ans);
    }
    return 0;
}