/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 11:04:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 11:04:59
*/

//服了
//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1281

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

const int N = 1005;

int n;
int startPos;
int boom;
int a[N];
int dp[55][N];

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &startPos, &boom);
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][startPos] = 1;
		for(int i=1;i<=n;i++){
			int changeSuccessfully;
			for(int j=0;j<=boom;j++){
				if(dp[i-1][j]){
					if(j + a[i] <= boom){
						dp[i][j + a[i]] = 1;
						changeSuccessfully = 1;
					}
					if(j - a[i] >= 0){
						dp[i][j - a[i]] = 1;
						changeSuccessfully = 1;
					}
				}
			}
			if(!changeSuccessfully){
				break;
			}
		}
		int flag = 0;
		for(int i=boom;i>=0;i--){
			if(dp[n][i]){
				printf("%d\n", i);
				flag = 1;
				break;
			}
		}
		if(!flag){
			printf("-1\n");
		}
	}
	return 0;
}