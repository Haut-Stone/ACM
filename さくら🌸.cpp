/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-27 23:13:56
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

const int N = 110;
const int INF = 99999999;

int hookNum;
int weightNum;
int hookPos[N];
int weight[N];
int dp[N][15000];

int main(void)
{
	while(~scanf("%d%d", &hookNum, &weightNum)){
		for(int i=1;i<=hookNum;i++){
			scanf("%d", &hookPos[i]);
		}
		for(int i=1;i<=weightNum;i++){
			scanf("%d", &weight[i]);
		}
		dp[0][7500] = 1;
		for(int i=1;i<=weightNum;i++){
			for(int k=0;k<=15000;k++){
				for(int j=1;j<=hookNum;j++){
					dp[i][k] += dp[i-1][k - hookPos[j]*weight[i]]; 
				}
			}
		}
		printf("%d\n", dp[weightNum][7500]);
	}
	return 0;
}