/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 12:15:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-23 11:15:59
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

const int N = 110;
const int INF = 0x3f3f3f3f;
int dp[N][N][N];
int w, h, m;

int main(void)
{
	w = h = m = 20;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=h;j++){
			dp[i][j][1] = i*j;
			for(int k=2;k<=m;k++){
				dp[i][j][k] = INF;
				for(int r=1;r<i;r++){
					dp[i][j][k]=min(dp[i][j][k],max(dp[r][j][k-1],(i-r)*j));
					for(int p=1;p<k;p++){
						dp[i][j][k]=min(dp[i][j][k],max(dp[r][j][p],dp[i-r][j][k-p]));
					}
				}

				for(int c=1;c<j;c++){
					dp[i][j][k]=min(dp[i][j][k],max(dp[i][c][k-1],(j-c)*i));
					for(int p=1;p<k;p++){
						dp[i][j][k]=min(dp[i][j][k],max(dp[i][c][p],dp[i][j-c][k-p]));
					}
				}
			}
		}
	}
	while(~scanf("%d%d%d", &w, &h, &m)){
		if(w == 0 || h == 0 || m == 0) break;
		printf("%d\n", dp[w][h][m]);
	}
	return 0;
}