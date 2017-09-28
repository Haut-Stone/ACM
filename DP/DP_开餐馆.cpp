/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-27 13:47:23
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-27 13:49:46
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1010;

int dp[N];
int iPre[N];// 记录里现在的这个点，最近的合法点的序号
int dis[N];
int money[N];

int n, mindis;


int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &mindis);
		for(int i=1;i<=n;i++){
			scanf("%d", &dis[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d", &money[i]);
		}
		memset(dp, 0, sizeof(dp));
		memset(iPre, 0, sizeof(iPre));
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>0;j--){
				if(dis[i] - dis[j] > mindis){
					iPre[i] = j;
					break;
				}
			}
		}
		dp[0] = 0;
		dp[1] = money[1];
		for(int i=2;i<=n;i++){
			//从小推倒大，分别是加这个点，和不加这个点两种情况。
			dp[i] = max(dp[i-1], dp[iPre[i]] + money[i]);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}
