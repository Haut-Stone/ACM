/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-27 12:22:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-27 13:09:01
*/

#include <iostream>
#include <cstring>

const int N = 10;

int m, n;
int dp[N][N];


void init()
{
	memset(dp, 0, sizeof(dp));
	for(int i=0;i<N;i++){
		dp[0][i] = 1;
	}
	for(int i=0;i<N;i++){
		for(int j=1;j<N;j++){
			if(i < j){
				dp[i][j] = dp[i][i];
			}else{
				// 这里就是不给新来的人查克拉的情况，加上每个人都分一下同样的查克拉的情况
				dp[i][j] = dp[i][j-1] + dp[i-j][j];
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	init();
	while(T--){
		scanf("%d%d", &m, &n);
		printf("%d\n", dp[m][n]);
	}
}