/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 21:48:45
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-01 12:34:07
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 400;
int dp[N][N];//表示从下到上，该点的最大和。

int main(void)
{
	// INPUT_TEST;

	int n;
	while(~scanf("%d", &n)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				scanf("%d", &dp[i][j]);
			}
		}
		for(int i=n-1;i>=1;i--){
			for(int j=1;j<=i;j++){
				dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);
			}
		}
		printf("%d\n", dp[1][1]);
	}
    return 0;
}