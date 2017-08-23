/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-23 10:29:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-23 10:30:18
*/

//这里面有几个经典的变形

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
// const int INF = 0x3f3f3f3f;

int numberNum;
int k;
int dp[N][N];
int even[N][N];
int odd[N][N];

int main(void)
{
	while(~scanf("%d%d", &numberNum, &k)){

		//正整数i划分成j个整数
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i=1;i<=numberNum;i++){
			for(int j=1;j<=numberNum;j++){
				if(i < j){
					dp[i][j] = 0;
				}else if(i > j){
					dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
				}else{
					dp[i][j] = 1;
				}
			} 
		}
		printf("%d\n", dp[numberNum][k]);

		//dp(i,j)表示正整数i划分为不超过j的不同整数的划分数
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(int i=1;i<=numberNum;i++){
			for(int j=1;j<=numberNum;j++){
				if(i < j){
					dp[i][j] = dp[i][i];
				}else if(i > j){
					dp[i][j] = dp[i-j][j-1] + dp[i][j-1];
				}else{
					dp[i][j] = dp[i][j-1] + 1;
				}
			}
		}
		printf("%d\n", dp[numberNum][numberNum]);

		//正整数i划分成奇数的组合
		memset(even, 0, sizeof(even));
		memset(odd, 0, sizeof(odd));
		even[0][0] = odd[0][0] = 1;
		for(int i=1;i<=numberNum;i++){
			for(int j=1;j<=i;j++){
				even[i][j] = odd[i-j][j];
				odd[i][j] = odd[i-1][j-1] + even[i-j][j];
			}
		}
		int num = 0;
		for(int i=0;i<=numberNum;i++){
			num += odd[numberNum][i];
		}
		printf("%d\n", num);
	}
	return 0;
}