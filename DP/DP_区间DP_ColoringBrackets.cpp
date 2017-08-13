/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-12 15:52:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-12 15:55:03
*/

//http://blog.csdn.net/sdjzping/article/details/19160013
//区间DP的题真的是。。。太麻烦了。看题解吧

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

const int N = 705;
const int MOD = 1e9 + 7;

char s[N];  
int match[N];  
int tmp[N];  
long long dp[N][N][3][3];  

void getMatch(int len)
{
	int p = 0;
	for(int i=0;i<len;i++){
		if(s[i] == '('){
			tmp[p++] = i;
		}else{
			match[i] = tmp[p-1];
			match[tmp[p-1]] = i;
			p--;
		}
	}
} 

void dfs(int l, int r)
{
	if(l + 1 == r){
		dp[l][r][0][1] = 1;//只有一对相等的情况
		dp[l][r][1][0] = 1;
		dp[l][r][0][2] = 1;
		dp[l][r][2][0] = 1;
		return;
	}
	if(match[l] == r){//所有区间端点相等的情况
		dfs(l+1, r-1);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(j != 1){
					dp[l][r][0][1] = (dp[l][r][0][1]+dp[l+1][r-1][i][j])%MOD;
				}
				if(i != 1){
					dp[l][r][1][0] = (dp[l][r][1][0]+dp[l+1][r-1][i][j])%MOD;
				}
				if(j != 2){
					dp[l][r][0][2] = (dp[l][r][0][2]+dp[l+1][r-1][i][j])%MOD;
				}
				if(i != 2){
					dp[l][r][2][0] = (dp[l][r][2][0]+dp[l+1][r-1][i][j])%MOD;
				}
			}
		}
		return;
	}else{//其他情况
		int p = match[l];
		dfs(l, p);
		dfs(p+1, r);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					for(int q=0;q<3;q++){
						if(!((k == 1 && q == 1) || (k == 2 && q == 2))){
							int temp = (dp[l][p][i][k]*dp[p+1][r][q][j])%MOD;
							dp[l][r][i][j] = (dp[l][r][i][j] + temp)%MOD;
						}
					}
				}
			}
		}
	}
}

int main(void)
{
	while(~scanf("%s", s)){
		int len = strlen(s);
		getMatch(len);//获得匹配的数组
		memset(dp, 0, sizeof(dp));
		dfs(0, len-1);//搜索

		long long ans = 0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				ans = (ans + dp[0][len-1][i][j]) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
}