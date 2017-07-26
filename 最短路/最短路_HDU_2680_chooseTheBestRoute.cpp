/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 23:33:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-20 00:07:10
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

const int N = 1010;//根据题目要求更该合适的数值
const int INF = 99999999;

//仅dijkstra中用到的
int vis[N];
int dis[N];

//需要在main中读取的值
int iMap[N][N];//先组织好图再求最短路
int vertexs;
int edges;//这里有个玄学问题，如果edges 放在vis[N],之前的话程序无法运行。。
int u, v, w;
int endX, beginX;


void init()
{
	for(int i=0;i<=vertexs;i++){
		for(int j=0;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}


int dijkstra(int beginX, int endX)
{	
	int min;
	int minVertex;

	//初始化
	for(int i=0;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=0;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=0;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;//如果没有更小的点了，直接退出。
		vis[minVertex]  = 1;
		for(int j=0;j<=vertexs;j++){
			if(iMap[minVertex][j] < INF){
				if(dis[minVertex] + iMap[minVertex][j] < dis[j]) dis[j] = dis[minVertex] + iMap[minVertex][j];
			}
		}
	}
	return dis[endX];
}

int main(void)
{
	// INPUT_TEST;
	while(~scanf("%d%d%d", &vertexs, &edges, &endX)){
		init();
		while(edges--){
			scanf("%d%d%d", &u, &v, &w);
			if(w < iMap[u][v]){//解决重边的问题,因为题干上有给，不然过不了的。
				iMap[u][v] = w;
			}
		}
		scanf("%d", &edges);
		while(edges--){
			scanf("%d", &beginX);
			iMap[0][beginX] = 0;
		}
		int ans = dijkstra(0, endX);
		if(ans == INF){
			printf("-1\n");
		}else{
			printf("%d\n", ans);
		}
	}	
    return 0;
}