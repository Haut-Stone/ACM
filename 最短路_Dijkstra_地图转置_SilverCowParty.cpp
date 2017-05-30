/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-26 16:36:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-26 17:04:47
*/

//POJ 3268 白书上的题:奶牛派对🎉
//对于矩阵转置的原因， 其实就是反转路径。看似是一target为起点，其实是以target为终点🏁

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

const int N = 1050;
const int INF = 99999999;

int vis[N];
int dis[N];
int pre[N];//记录路径的数组
int res[N];
int ans;

int iMap[N][N];
int vertexs;
int edges;
int target;
int u, v, w;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
	memset(res, 0, sizeof(res));
}


int dijkstra(int beginX, int endX)
{	
	int min;
	int minVertex = 0;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
		pre[i] = dis[i] != INF && i != beginX ? beginX : -1;//想将所有有链接的点的前一个点，设为出发点
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;//如果没有更小的点了，直接退出。
		vis[minVertex]  = 1;
		res[minVertex] += min;//这里加了这么一句
		int u = minVertex;
		for(int v=1;v<=vertexs;v++){
			if(iMap[u][v] < INF){
				if(dis[u] + iMap[u][v] < dis[v]){
					 dis[v] = dis[u] + iMap[u][v];
					 pre[v] = u;
				}
			}
		}
	}
	return dis[endX];
}

void transfrom()
{
	//矩阵转置
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=i;j++){
			int temp;
			temp = iMap[i][j];
			iMap[i][j] = iMap[j][i];
			iMap[j][i] = temp;
		}
	}
}

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d%d%d", &vertexs, &edges, &target)){
		init();
		for(int i=0;i<edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			iMap[u][v] = w;//在本题中是有向边。
		}
		dijkstra(target, vertexs);
		transfrom();//用转置来解决从target出发的情况
		dijkstra(target, vertexs);

		ans = 0;
		for(int i=1;i<=vertexs;i++){
			ans = max(ans, res[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}