/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-26 13:35:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-26 13:50:37
*/

//POJ 1837
//背包的问题，寻找状态转移。其实就是把所有的状态转移的镜像全都拍了下来
//这题就是用dp拍下了所有的状态快照

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

int dp[21][15001];
int hookPos[100];
int weight[100];

int main(void)
{
	int hooksNumber;
	int weightsNumber;

	while(~scanf("%d%d", &hooksNumber, &weightsNumber)){
		for(int i=1;i<=hooksNumber;i++){
			scanf("%d", &hookPos[i]);
		}
		for(int i=1;i<=weightsNumber;i++){
			scanf("%d", &weight[i]);
		}

		memset(dp, 0, sizeof(dp));
		dp[0][7500] = 1;

		for(int weightNum=1;weightNum<=weightsNumber;weightNum++){
			for(int balanceDegree=0;balanceDegree<15000;balanceDegree++){
				if(dp[weightNum-1][balanceDegree]){
					for(int hook=1;hook<=hooksNumber;hook++){
						int newBalanceDegree = balanceDegree + weight[weightNum]*hookPos[hook];
						dp[weightNum][newBalanceDegree] += dp[weightNum-1][balanceDegree];
					}
				}
			}
		}
		printf("%d\n", dp[weightsNumber][7500]);
	}
	return 0;
}