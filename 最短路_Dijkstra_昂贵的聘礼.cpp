/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-24 20:18:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 20:20:58
*/

//POJ 1062
//这道题的要在dij的同时，加上等级块限制，让等级块从最高值为酋长等级，慢慢滑动到最低值为酋长等级

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

int iMap[N][N];
int value[N], level[N];
int dis[N], vis[N];
int canExchange[N];
int levelLimit;
int n;

//初始化地图块
void init()
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}

//求符合条件的最短路
int dij()
{
	int res = INF;
	int minVertex = 0;
	int minCost;

	for(int i=1;i<=n;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	dis[1] = 0;

	for(int i=1;i<=n;i++){
		minCost = INF;
		for(int j=1;j<=n;j++){
			if(dis[j] <= minCost && !vis[j] && canExchange[j]){
				minCost = dis[j];
				minVertex = j;
			}
		}
		if(minCost == INF) break;
		vis[minVertex] = 1;
		int u = minVertex;
		for(int v=1;v<=n;v++){
			if(canExchange[v]){
				dis[v] = min(dis[v], dis[u] + iMap[u][v]);
			}
		}
	}

	for(int j=1;j<=n;j++){
		dis[j] += value[j];
		res = min(res, dis[j]);
	}
	return res;
}

int main(void)
{
	scanf("%d%d", &levelLimit, &n);
	init();
	for(int i=1;i<=n;i++){
		int exchangeNum;
		scanf("%d%d%d", &value[i], &level[i], &exchangeNum);
		for(int j=1;j<=exchangeNum;j++){
			int id, exchangeValue;
			scanf("%d%d", &id, &exchangeValue);
			iMap[i][id] = exchangeValue;//将交换关系存为有向图
		}
	}
	int kingsLevel = level[1];
	int minCost = INF;
	for(int i=0;i<=levelLimit;i++){
		memset(canExchange, 0, sizeof(canExchange));
		for(int j=1;j<=n;j++){
			//一个时刻移动的可交易区间
			//这里是这道题的难点所在
			if(level[j] >= kingsLevel-levelLimit+i && level[j]<=kingsLevel+i){
				canExchange[j] = 1;
			}
		}
		minCost = min(minCost, dij());
	}
	printf("%d\n", minCost);
	return 0;
}