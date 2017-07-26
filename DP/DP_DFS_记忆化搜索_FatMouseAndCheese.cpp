/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-20 11:39:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-20 11:40:44
*/

//HDU 1078
//简单的记忆化搜索题

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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1010;

int a[N][N];
int dp[N][N];
int Distance[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n;
int k;

int check(int x, int y)
{
	if(x<1 || y<1 || x>n|| y>n){
		return 1;
	}else{
		return 0;
	}
}

int dfs(int x, int y)
{
	int ans = 0;

	if(!dp[x][y]){
		for(int i=1;i<=k;i++){
			for(int j=0;j<4;j++){
				int dx = x + Distance[j][0] * i;
				int dy = y + Distance[j][1] * i;
				if(check(dx, dy)){
					continue;
				}else{
					if(a[dx][dy] > a[x][y]){
						ans = max(ans, dfs(dx, dy));
					}
				}
			}
		}
		dp[x][y] = ans + a[x][y];
	}
	return dp[x][y];
}

int main(void)
{	
	// INPUT_TEST;
	while(scanf("%d%d", &n, &k), n>0 && k>0){
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &a[i][j]);
			}
		}
		printf("%d\n", dfs(1, 1));
	}
	return 0;
}