/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 20:14:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-15 19:04:37
*/

//题目来自于白书 P57
//

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

const int N = 100;

int dp[N][N];//装前i件物品，容量为j时的最大值
int weight[N];//单个的重量
int value[N];//单个的价值

int num;
int maxCapacity;
int ans;

int package(int index, int maxCapacity)
{
	for(int i=0;i<=num;i++){
		for(int j=0;j<=maxCapacity;j++){
			if(j < weight[i]){
				dp[i+1][j] = dp[i][j];//如果装不下这个物品
			}else{
				dp[i+1][j] = max(dp[i][j], dp[i+1][j - weight[i]] + value[i]);//简化后的递推公式
			}
		}
	}
	return dp[num][maxCapacity];
}

int main(void)
{
	INPUT_TEST;
	scanf("%d %d", &num, &maxCapacity);
    for(int i=0;i<num;i++){
        scanf("%d %d", &weight[i], &value[i]);
    }
    memset(dp, 0, sizeof(dp));
    ans = package(0, maxCapacity);
    printf("%d\n", ans);
    return 0;
}