/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-15 19:47:45
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-15 19:48:16
*/


//这种用的是一维的dp数组，来轮换解决问题，节省大量的空间
//这题有点不一样的是求最小价值。当模版用时要适当的改一下

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

const int N = 550;
const int INF = 0x3f3f3f3f;

int dp[10010];
int weight[N];
int value[N];
int n;;
int rawWeight;
int lastWeight;
int iconWeight;
int ans;

void package()
{
	dp[0] = 0;
	for(int i=0;i<n;i++){
		for(int j=weight[i];j<=iconWeight;j++){
			if(dp[j - weight[i]] < INF){
				dp[j] = min(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
	}
	ans = dp[iconWeight];
}

int main(void)
{
	INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		cin>>rawWeight>>lastWeight>>n;
		for(int i=0;i<n;i++){
			cin>>value[i]>>weight[i];
		}
		iconWeight = lastWeight - rawWeight;
		for(int i=0;i<=iconWeight;i++) dp[i] = INF;
		ans = 0;
		package();
		if(ans >= INF){
			printf("This is impossible.\n");
		}else{
			printf("The minimum amount of money in the piggy-bank is %d.\n", ans);
		}
	}
	return 0;
}