/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:01:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 17:23:05
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
				if(temp == 0) iMap[i] += (1<<(j-1));
			}
		}

		int all = 0;
		for(int i=0;i<(1<<col);i++){
			if(!haveAdjacentOne(i)){
				status[all++] = i;
			}
		}

		for(int i=0;i<all;i++){
			if(!haveInvisablePos(1, i)){
				dp[1][i] = 1;
			}
		}

		for(int i=2;i<=row;i++){
			for(int j=0;j<all;j++){
				if(!haveInvisablePos(i, j)){
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
