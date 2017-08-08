/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-07 17:12:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 17:14:39
*/

//POJ 3254
//状压DP真的是把二进制玩的出神入化啊

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

const int N = 100010;
const int M = 14;
const int MOD = 1e9;

int row, col;
int dp[M][N];
int status[N];
int iMap[M];
int temp;

bool haveAdjacentOne(int n)
{
	return (n&(n<<1));
}

bool haveInvisablePos(int a, int b)
{
	return iMap[a]&status[b];
}

int main(void)
{
	while(~scanf("%d%d", &row, &col)){
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				scanf("%d", &temp);
				if(temp == 0){
					iMap[i] += (1<<(j-1));//注意这里的图是反着的，并且01反转了
				}
			}
		}
		int all = 0;
		for(int i=0;i<(1<<col);i++){//生成不相邻情况
			if(!haveAdjacentOne(i)){
				status[all++] = i;
			}
		}
		
		for(int i=0;i<all;i++){
			if(!haveInvisablePos(1, i)){//选择出可以放置的不相邻情况,放置到第一行
				dp[1][i] = 1;
			}
		}
		
		for(int i=2;i<=row;i++){
			for(int j=0;j<all;j++){
				if(!haveInvisablePos(i, j)){//该情况可以放置到当前行
					for(int k=0;k<all;k++){
						if(!haveInvisablePos(i-1, k)){
							if(!(status[j]&status[k])){
								dp[i][j] += dp[i-1][k];
							}
						}
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=0;i<all;i++){
			ans += dp[row][i];
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}