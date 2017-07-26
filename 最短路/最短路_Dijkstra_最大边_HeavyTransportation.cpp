/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-26 13:42:29
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-26 14:29:10
*/

//POJ 1797
//模版题，只不过判断条件稍微换了下。

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

const int N = 2020;
const int NINF = -1;

int vis[N];
int dis[N];


int iMap[N][N];
int vertexs;
int edges;
int T;
int u, v, w;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			iMap[i][j] = 0;
		}
	}
}

int Imin(int a, int b)
{
	return a < b ? a:b;
}

int dijkstra(int beginX, int endX)
{	
	int max;
	int maxVertex = 0;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];//这里dis数组的意义改变了。意思是最大承载量
		vis[i] = 0;
	}

	for(int i=1;i<=vertexs;i++){//搜遍所有的点
		max = NINF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] > max && !vis[j]){
				max = dis[j];
				maxVertex = j;
			}
		}
		vis[maxVertex]  = 1;

		int u = maxVertex;
		for(int v=1;v<=vertexs;v++){
			if(!vis[v]){
				if(Imin(dis[u], iMap[u][v]) > dis[v]){
					 dis[v] = Imin(dis[u], iMap[u][v]);
				}
			}
		}
	}
	return dis[endX];
}

int main(void)
{
	// INPUT_TEST;

	cin>>T;
	int cas = 1;
	while(T--){
		init();
		cin>>vertexs>>edges;
		for(int i=1;i<=edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			iMap[u][v] = iMap[v][u] = w;
		}
		printf("Scenario #%d:\n%d\n\n", cas++, dijkstra(1, vertexs));	
	}
    return 0;
}