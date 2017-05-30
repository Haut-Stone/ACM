/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-26 13:04:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-26 13:36:25
*/

//POJ 2253
//就是最短路，但是要求的东西不一样，比较绕:但是注意，这里求的是青蛙a所在的石头到青蛙b所在石头的路径上的最大边的值，所以松弛操作要稍微变一下形。

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

const int N = 2020;
const int INF = 99999999;

int vis[N];
double dis[N];
int pre[N];//记录路径的数组

double iMap[N][N];
int vertexs;
int edges;
int x[N];
int y[N];

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
}

double Imax(double a, double b)
{
	return a > b ? a:b;
}

double Imin(double a, double b)
{
	return a < b ? a:b;
}

double dijkstra(int beginX, int endX)
{	
	double min;
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

		int u = minVertex;
		for(int v=1;v<=vertexs;v++){
			if(iMap[u][v] < INF){
				dis[v] = Imin(dis[v], Imax(dis[u], iMap[u][v]));//这道题主要是这里的判断条件不同，题意比较绕
			}
		}
	}
	return dis[endX];
}


double getDis(int x1, int x2, int y1, int y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(void)
{
	// INPUT_TEST;

	int cas = 1;

	while(cin>>vertexs){
		init();
		if(vertexs == 0) break;
		for(int i=1;i<=vertexs;i++){
			scanf("%d%d", &x[i], &y[i]);
		}
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				iMap[i][j] = getDis(x[i], x[j], y[i], y[j]);
			}	
		}
		printf("Scenario #%d\nFrog Distance = %.3f\n\n", cas++, dijkstra(1, 2));
	}
	return 0;
}