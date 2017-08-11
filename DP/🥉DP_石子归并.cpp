/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 20:48:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-11 17:06:02
*/

//少见的写的好的代码，简单的dp问题，但是对于我依旧不简单

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

const int N = 5;
const int INF = 0x3f3f3f3f;

int dp[N][N];
int a[N];
int sum[N][N];

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);//读入数据
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum[i][j] = sum[i][j-1] + a[j];//求和
			}
		}
		memset(dp, INF, sizeof(dp));
		for(int i=1;i<=n;i++){
			dp[i][i] = 0;//自己和自己合并的代价是0
		}
		for(int j=1;j<=n;j++){
			for(int i=j-1;i>=1;i--){
				for(int k=i;k<=j;k++){
					printf("%d %d\n", dp[i][j], dp[i][k] + dp[k+1][j] + sum[i][j]);
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[i][j]);//从小区间推到大区间
					//用k分割把区间一个一个全部试了
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}