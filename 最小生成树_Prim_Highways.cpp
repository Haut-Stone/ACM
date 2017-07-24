/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-24 14:06:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 14:07:02
*/

//POJ 2485
//基础题，只不过把求和换成了求最大值

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

const int N = 1000;
const int INF = 99999999;

int iMap[N][N];
int vis[N];
int minCost[N];
int n;

int prim()
{
	int ans = 0;
	for(int i=0;i<n;i++){
		minCost[i] = iMap[0][i];
		vis[i] = 0;
	}
	vis[0] = 1;

	while(true){
		int minDis = INF;
		int minPos = 0;
		for(int i=0;i<n;i++){
			if(minCost[i] < minDis && !vis[i]){
				minDis = minCost[i];
				minPos = i;
			}
		}
		if(minDis == INF) break;

		vis[minPos] = 1;
		ans = max(ans, minDis);
		for(int i=0;i<n;i++){
			if(!vis[i] && minCost[i] > iMap[minPos][i]){
				minCost[i] = iMap[minPos][i];
			}
		}
	}
	return ans;
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d", &iMap[i][j]);
			}
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}